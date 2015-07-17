#define _WIN32_DCOM
#include <iostream>

#include <hx/CFFI.h>
#include <windows.h>
#include <process.h>
#include <comdef.h>
#include <comip.h>
#include <comdefsp.h>
#include <dshow.h>
#include <vector>

#pragma comment(lib,"strmiids.lib")

#include <string>
using namespace std;
using std::string;

namespace nativecamera {

	std::string getWindowsDeviceIdentifier()
	{
		std::string deviceIdentifier = "Webcam device identifier";
		return deviceIdentifier;
	}

	std::string initializeWindowsCamera()
	{
		HRESULT hr;

		ICreateDevEnum *pSysDevices = NULL;
		
		IEnumMoniker *pCameras = NULL;
		IMoniker *pCamera = NULL;
		
		if(FAILED(CoInitialize(NULL)))
		{
			//setError("CoInitialize Failed");
			return NULL ;
		}
		
		// 1) Instantiating all available system devices list (enumerator)
		hr = CoCreateInstance(CLSID_SystemDeviceEnum, NULL, CLSCTX_INPROC_SERVER,
			IID_ICreateDevEnum, (void **)&pSysDevices);
		if (FAILED(hr))
		{
			//wprintf(L"Can't instantiate available system devices enumerator!");
			//_getch();
			return NULL;
		}
		
		// 2) Instantiating available video capturing devices (cameras) enumerator
		hr = pSysDevices->CreateClassEnumerator(CLSID_VideoInputDeviceCategory, &pCameras, 0);
		if (FAILED(hr))
		{
			return NULL;
		}
		
		// 3) Enumerating all cameras
		ULONG cFetched;
		hr = pCameras->Next(1, &pCamera, &cFetched);
		if (FAILED(hr))
		{
			return NULL;
		}

		// 4) Instantiating IGraphBuilder
		IGraphBuilder *pGraphBuilder = NULL;
		hr = CoCreateInstance(CLSID_FilterGraph, 0, CLSCTX_INPROC_SERVER, IID_IGraphBuilder, (void **)&pGraphBuilder);
		if (FAILED(hr))
		{
			return NULL;
		}

		// 5) Instatiating ICaptureGraphBuilder2
		ICaptureGraphBuilder2 *pCaptureGraphBuilder = NULL;
		hr = CoCreateInstance(CLSID_CaptureGraphBuilder2, 0,
			CLSCTX_INPROC_SERVER, IID_ICaptureGraphBuilder2, (void **)&pCaptureGraphBuilder);
		if (FAILED(hr))
		{
			return NULL;
		}

		// 6) Setting graph builder as an filtergraph for capture graph builder
		pCaptureGraphBuilder->SetFiltergraph(pGraphBuilder);

		// 7) Instatiating IBaseFilter
		IBaseFilter *pVideoCaptureFilter;
		hr = pCamera->BindToObject(0, 0, IID_IBaseFilter, (void **)&pVideoCaptureFilter);
		if (FAILED(hr))
		{
			return NULL;
		}

		// 8) Adding video capture filter as filter to graph builder
		pGraphBuilder->AddFilter(pVideoCaptureFilter, L"VideoCaptureFilter");

		// 9) Rendering video capturing stream
		hr = pCaptureGraphBuilder->RenderStream
			(&PIN_CATEGORY_PREVIEW, NULL, pVideoCaptureFilter, NULL, NULL);
		if (FAILED(hr))
		{
			return NULL;
		}

		// 10) Instantiating IVideoWindow (for video stream)
		IVideoWindow *pVideoWindow;
		hr = pGraphBuilder->QueryInterface(IID_IVideoWindow, (void **)&pVideoWindow);

		// 11) Setting video window to visible
		pVideoWindow->put_Visible(true);

		// 12) Instantiating a media control
		IMediaControl *pMediaControl;
		hr = pGraphBuilder->QueryInterface(IID_IMediaControl, (void **)&pMediaControl);

		// 13) Running rendered stream
		pMediaControl->Run();
		wprintf(L"Capturing...");
		
		std::string result = "yes ?";

		return result;
	}

}