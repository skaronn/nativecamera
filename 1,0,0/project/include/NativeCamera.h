#ifndef NATIVECAMERA_H
#define NATIVECAMERA_H

namespace nativecamera {
	const char* getDeviceIdentifier();
	void initialize();
	/*
	bool takePhoto(int maxPixelSize, float jpegQuality, const char* cameraOverlayFile);
	bool takeVideo();
	*/
}


#endif