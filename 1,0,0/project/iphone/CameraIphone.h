#ifndef CAMERAIPHONE_H
#define CAMERAIPHONE_H

namespace nativecamera
{
    namespace iphone
    {
        int getDeviceNumber();
		void initializeIphoneCamera();
        bool takePhoto(int maxPixelSize, float jpegQuality, const char* cameraOverlayFile);
		bool takeVideo();
    }
}


#endif