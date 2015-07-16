#ifndef STATIC_LINK
#define IMPLEMENT_API
#endif

#if defined(HX_WINDOWS) || defined(HX_MACOS) || defined(HX_LINUX)
#define NEKO_COMPATIBLE
#endif

#include <hx/CFFI.h>
#include "NativeCamera.h"

using namespace nativecamera;

static value nativecamera_device_number() {
	int returnValue = getDeviceNumber();
	return alloc_int(returnValue);
}
DEFINE_PRIM (nativecamera_device_number, 0);

static value nativecamera_initialize() {
	initialize();
}
DEFINE_PRIM (nativecamera_initialize, 0);

static value nativecamera_take_photo(value maxPixelSize, value jpegQuality, value cameraOverlayFile) 
{
    return alloc_bool(takePhoto(val_int(maxPixelSize), (float) val_float(jpegQuality), val_string(cameraOverlayFile)));
}
DEFINE_PRIM(nativecamera_take_photo, 3);

static value nativecamera_take_video() {
{
    return alloc_bool(takeVideo());
}
DEFINE_PRIM(nativecamera_take_video, 0);

/*
extern "C" void nativecamera_main () {
	
	val_int(0); // Fix Neko init
	
}
DEFINE_ENTRY_POINT (nativecamera_main);


extern "C" int nativecamera_register_prims () { return 0; }
*/