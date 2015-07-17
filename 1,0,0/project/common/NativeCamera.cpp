#include "NativeCamera.h"
#include "../iphone/CameraIPhone.h"
#include "../windows/CameraWindows.h"

#include <string>
using namespace std;
using std::string;

namespace nativecamera {
		
	const char* getDeviceIdentifier() {
		std::string deviceNumber = "XXXXX-0123456789";
		#ifdef HX_WINDOWS
		deviceNumber = getWindowsDeviceIdentifier();
		#elif IPHONE
        deviceNumber = iphone::getDeviceNumber();
        #endif
		return deviceNumber.c_str();		
	}
	
	const char* initialize() {	
		std::string data;
		#ifdef HX_WINDOWS
		data = initializeWindowsCamera();
		#elif IPHONE
        iphone::initializeIphoneCamera();
        #endif
		return data.c_str();
	}
	
	bool takePhoto(int maxPixelSize, float jpegQuality, const char* cameraOverlayFile) {		
		return true;
	}
	
	bool takeVideo() {
		return true;
	}
	
}