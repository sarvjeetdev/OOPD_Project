#include "Device.h"
#include "AccessPoint.h"  // Include AccessPoint.h to use AccessPoint in the methods
#include <iostream>

// Constructor: Initializes device with a name
Device::Device(const std::string& deviceName)
    : deviceName(deviceName), connectionStatus(false) {}

// Connect the device to an Access Point
void Device::connectToAP(AccessPoint* ap) {
    std::cout << "Connecting " << deviceName << " to Access Point...\n";
    ap->connectDevice(this);
    connectionStatus = true;
}

// Disconnect the device from an Access Point
void Device::disconnectFromAP(AccessPoint* ap) {
    std::cout << "Disconnecting " << deviceName << " from Access Point...\n";
    ap->disconnectDevice(this);
    connectionStatus = false;
}

// Get the name of the device
const std::string& Device::getDeviceName() const {
    return deviceName;
}

// Get the connection status of the device
bool Device::getConnectionStatus() const {
    return connectionStatus;
}

// Set the connection status of the device
void Device::setConnectionStatus(bool status) {
    connectionStatus = status;
}
