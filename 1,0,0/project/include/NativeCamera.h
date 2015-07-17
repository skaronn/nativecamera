#ifndef NATIVECAMERA_H
#define NATIVECAMERA_H

#include <string>
using namespace std;
using std::string;

namespace nativecamera {
	const char* getDeviceIdentifier();
	const char* initialize();
	bool takePhoto(int maxPixelSize, float jpegQuality, const char* cameraOverlayFile);
	bool takeVideo();
}


#endif