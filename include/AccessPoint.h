#ifndef ACCESSPOINT_H
#define ACCESSPOINT_H

#include <string>  // Include <string> for std::string
#include <vector>  // Include <vector> for storing connected devices
#include "Device.h"  // Include Device.h to inherit from Device

class AccessPoint : public Device {
public:
    AccessPoint(const std::string& ssid, int bandwidth);  // Constructor

    void connectDevice(Device* device);  // Connect a device to the access point
    void disconnectDevice(Device* device);  // Disconnect a device from the access point

    const std::string& getSSID() const;  // Get the SSID of the AP
    int getBandwidth() const;  // Get the bandwidth of the AP
    std::vector<Device*> getConnectedDevices() const;  // Get the list of connected devices

private:
    std::string ssid;  // WiFi name
    int bandwidth;  // Maximum bandwidth
    std::vector<Device*> connectedDevices;  // List of devices connected to this AP
};

#endif // ACCESSPOINT_H
