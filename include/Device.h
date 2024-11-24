#ifndef DEVICE_H
#define DEVICE_H

#include <string>  // Include <string> for std::string

// Forward declaration of AccessPoint class
class AccessPoint;

class Device {
public:
    // Constructor to initialize the device with a name
    Device(const std::string& deviceName);

    // Methods using AccessPoint
    void connectToAP(AccessPoint* ap);  // Connect the device to an Access Point
    void disconnectFromAP(AccessPoint* ap);  // Disconnect the device from an Access Point

    const std::string& getDeviceName() const;  // Get the device name
    bool getConnectionStatus() const;  // Get the connection status of the device
    void setConnectionStatus(bool status);  // Set the connection status

private:
    std::string deviceName;  // Store the device name
    bool connectionStatus;  // Store the connection status
};

#endif // DEVICE_H
