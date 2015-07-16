#ifndef NATIVECAMERA_H
#define NATIVECAMERA_H

namespace nativecamera {
	int getDeviceNumber();
	void initialize();
	bool takePhoto(int maxPixelSize, float jpegQuality, const char* cameraOverlayFile);
	bool takeVideo();
}


#endif