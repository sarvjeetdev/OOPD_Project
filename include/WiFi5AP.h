#ifndef WIFI5AP_H
#define WIFI5AP_H

#include "AccessPoint.h"
#include "Device.h"
#include <vector>

class WiFi5AP : public AccessPoint {
public:
    WiFi5AP(const std::string& ssid, int bandwidth);

    // Simulate WiFi 5 communication
    void simulateCommunication(int numUsers);

    // Calculate throughput, average latency, and maximum latency
    void calculateMetrics(int numUsers);

private:
    std::vector<Device*> devices;
    double totalData;
    double totalTime;
    double maxLatency;
    double avgLatency;
    double transmissionRate;  // Transmission rate in Mbps
};

#endif // WIFI5AP_H
