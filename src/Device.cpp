#include "Device.h"

// Constructor for initializing a device with unique ID, bandwidth, and modulation scheme
Device::Device(const std::string& id, double bandwidth, const std::string& mod)
    : device_id(id), supported_bandwidth(bandwidth), modulation(mod) {}

// Destructor (already virtual in the base class to handle derived class cleanup)
Device::~Device() {
    // No specific cleanup required in base class
}
