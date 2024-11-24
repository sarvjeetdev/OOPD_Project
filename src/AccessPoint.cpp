#include "AccessPoint.h"
#include "Device.h"  // Include Device.h to use Device in the methods
#include <iostream>
#include<algorithm>

// Constructor: Initializes AccessPoint with ssid and bandwidth
AccessPoint::AccessPoint(const std::string& ssid, int bandwidth)
    : Device(ssid), ssid(ssid), bandwidth(bandwidth) {}  // Call Device constructor with ssid

// Connect a device to the Access Point
void AccessPoint::connectDevice(Device* device) {
    std::cout << "Device connected to Access Point: " << device->getDeviceName() << "\n";
    connectedDevices.push_back(device);
}

// Disconnect a device from the Access Point
void AccessPoint::disconnectDevice(Device* device) {
    std::cout << "Device disconnected from Access Point: " << device->getDeviceName() << "\n";
    connectedDevices.erase(std::remove(connectedDevices.begin(), connectedDevices.end(), device), connectedDevices.end());
}

// Get the SSID of the Access Point
const std::string& AccessPoint::getSSID() const {
    return ssid;
}

// Get the bandwidth of the Access Point
int AccessPoint::getBandwidth() const {
    return bandwidth;
}

// Get the list of connected devices
std::vector<Device*> AccessPoint::getConnectedDevices() const {
    return connectedDevices;
}
