#ifndef DEVICE_H
#define DEVICE_H

#include <string>

class Device {
protected:
    std::string device_id;         // Unique identifier for the device
    double supported_bandwidth;    // Supported bandwidth (in MHz or another unit)
    std::string modulation;        // Modulation scheme (e.g., 256-QAM, QPSK, etc.)

public:
    Device(const std::string& id, double bandwidth, const std::string& mod)
        : device_id(id), supported_bandwidth(bandwidth), modulation(mod) {}

    // Getter and Setter for device_id
    std::string getDeviceId() const { return device_id; }
    void setDeviceId(const std::string& id) { device_id = id; }

    // Getter and Setter for supported_bandwidth
    double getSupportedBandwidth() const { return supported_bandwidth; }
    void setSupportedBandwidth(double bandwidth) { supported_bandwidth = bandwidth; }

    // Getter and Setter for modulation
    std::string getModulation() const { return modulation; }
    void setModulation(const std::string& mod) { modulation = mod; }

    // Pure virtual functions for sending and receiving data
    virtual void sendData() = 0;
    virtual void receiveData() = 0;

    // Virtual destructor for proper cleanup
    virtual ~Device() {}
};

#endif // DEVICE_H
