#include "NativeCamera.h"
#include "../iphone/CameraIPhone.h"
#include "../windows/CameraWindows.h"

namespace nativecamera {
		
	const char* getDeviceIdentifier() {
		const char* deviceNumber = "0123456789";
		#ifdef IPHONE
        deviceNumber = iphone::getDeviceNumber();
        #endif
		return deviceNumber;		
	}
	
	void initialize() {	
		#ifdef HX_WINDOWS
		std::string GetResolution();
		#elif IPHONE
        iphone::initialize();
        #endif
	}
	
	bool takePhoto(int maxPixelSize, float jpegQuality, const char* cameraOverlayFile) {		
		return true;
	}
	
	bool takeVideo() {
		return true;
	}
	
}