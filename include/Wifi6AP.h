#ifndef WIFI6AP_H
#define WIFI6AP_H

#include "AccessPoint.h"
#include <vector>
#include <string>

class WiFi6AP : public AccessPoint {
public:
    WiFi6AP(const std::string& ssid, int bandwidth);

    void simulateCommunication(int numUsers);
    void calculateMetrics(int numUsers);

private:
    double transmissionRate;
    long totalData;
    long totalTime;
    double maxLatency;
    double avgLatency;
    std::vector<Device*> devices; // List of devices connected to the AP
};

#endif // WIFI6AP_H
