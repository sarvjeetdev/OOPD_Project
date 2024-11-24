#ifndef WIFI4AP_H
#define WIFI4AP_H

#include "AccessPoint.h"
#include "Device.h"
#include <vector>
#include <random>

class WiFi4AP : public AccessPoint {
public:
    WiFi4AP(const std::string& ssid, int bandwidth);
    
    // Simulate WiFi 4 communication for given number of users
    void simulateCommunication(int numUsers);

    // Calculate throughput, average latency, and maximum latency
    void calculateMetrics(int numUsers);

private:
    std::vector<Device*> devices;
    double transmissionRate;  // Transmission rate in Mbps
    double totalData;         // Total data transmitted in KB
    double totalTime;         // Total time for transmission in seconds
    double maxLatency;        // Maximum latency
    double avgLatency;        // Average latency
};

#endif // WIFI4AP_H
