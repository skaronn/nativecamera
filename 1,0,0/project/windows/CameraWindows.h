#ifndef DEVICE_H
#define DEVICE_H

#include <string>
using namespace std;
using std::string;

namespace nativecamera {

	std::string getWindowsDeviceIdentifier();
	std::string initializeWindowsCamera();

}

#endif