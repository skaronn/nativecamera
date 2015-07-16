#include "NativeCamera.h"

namespace nativecamera {
		
	int getDeviceNumber() {		
		return 123456789;		
	}
	
	void initialize() {				
	}
	
	bool takePhoto(int maxPixelSize, float jpegQuality, const char* cameraOverlayFile) {		
		return true;
	}
	
	bool takeVideo() {
		return true;
	}
	
}