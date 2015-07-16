#ifndef CAMERAIPHONE_H
#define CAMERAIPHONE_H

namespace camera
{
    namespace iphone
    {
        int getDeviceNumber();
		void initialize();
        bool takePhoto(int maxPixelSize, float jpegQuality, const char* cameraOverlayFile);
		bool takeVideo();
    }
}


#endif