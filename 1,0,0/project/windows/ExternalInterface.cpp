#include "Device.h"

#include <hx/CFFI.h>
#include <string>

using std::string;
using namespace nativecamera;

static value nativecamera_getPixels () {
	std::string data = GetData();
	value result =  alloc_string(data.c_str());
	return result;
}
DEFINE_PRIM (nativecamera_getPixels, 0);

static value nativecamera_getResolution () {
	std::string data = GetResolution();
	value result =  alloc_string(data.c_str());
	return result;
}
DEFINE_PRIM (nativecamera_getResolution, 0);
