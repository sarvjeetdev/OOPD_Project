#ifndef WIFI4AP_H
#define WIFI4AP_H

#include "AccessPoint.h"
#include "Channel.h"
#include "User.h"
#include <vector>
#include <cstdlib>  // For random backoff time generation
#include <ctime>    // For seeding the random number generator
#include <algorithm> // For calculating max latency
#include <numeric>   // For calculating average latency

class WiFi4AP : public AccessPoint {
private:
    Channel channel;                       // Channel used by the WiFi 4 AP
    std::vector<User*> connected_users;    // List of users connected to this AP
    double max_backoff_time;               // Maximum backoff time in milliseconds
    double total_data_transmitted;         // Total data transmitted in bytes
    double total_time;                     // Total simulation time in milliseconds
    std::vector<double> latencies;         // List of latencies for packets

    // Helper function to generate a random backoff time
    double generateRandomBackoffTime() const;

public:
    // Constructor
    WiFi4AP(const Channel& chan, double maxBackoff = 10.0);

    // Connect a user to the AP
    void connectUser(User* user) override;

    // Disconnect a user from the AP
    void disconnectUser(User* user) override;

    // Simulate transmission process
    void transmit() override;

    // Calculate and return throughput in Mbps
    double calculateThroughput() const;

    // Calculate and return average latency
    double calculateAverageLatency() const;

    // Get the maximum latency recorded
    double getMaxLatency() const;
};

#endif // WIFI4AP_H
