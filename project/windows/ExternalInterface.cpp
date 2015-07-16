#include "Device.h"

#include <hx/CFFI.h>
#include <string>

using std::string;
using namespace nativecamera;

static value nativedevice_getPixels () {
	std::string data = GetData();
	value result =  alloc_string(data.c_str());
	return result;
}
DEFINE_PRIM (nativedevice_getPixels, 0);

static value nativedevice_getResolution () {
	std::string data = GetResolution();
	value result =  alloc_string(data.c_str());
	return result;
}
DEFINE_PRIM (nativedevice_getResolution, 0);
