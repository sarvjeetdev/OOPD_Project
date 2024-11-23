#include "WiFi4AP.h"
#include <iostream>
#include <limits>  // For setting latency to max double

// Constructor initializes the channel and sets max backoff time
WiFi4AP::WiFi4AP(const Channel& chan, double maxBackoff)
    : channel(chan), max_backoff_time(maxBackoff), total_data_transmitted(0), total_time(0) {
    std::srand(static_cast<unsigned>(std::time(0))); // Seed the random number generator
}

// Connect a user to the AP
void WiFi4AP::connectUser(User* user) {
    connected_users.push_back(user);
}

// Disconnect a user from the AP
void WiFi4AP::disconnectUser(User* user) {
    connected_users.erase(std::remove(connected_users.begin(), connected_users.end(), user), connected_users.end());
}

// Helper function to generate a random backoff time within the max limit
double WiFi4AP::generateRandomBackoffTime() const {
    return static_cast<double>(std::rand()) / RAND_MAX * max_backoff_time;
}

// Simulate the transmission process for connected users
void WiFi4AP::transmit() {
    const int PACKET_SIZE = 1024; // Each packet is 1 KB (1024 bytes)
    for (User* user : connected_users) {
        bool packet_transmitted = false;
        double start_time = total_time;  // Record the start time of transmission

        while (!packet_transmitted) {
            if (!channel.isBusy()) {
                // If channel is free, transmit the packet
                channel.setBusy(true); // Mark channel as busy
                total_data_transmitted += PACKET_SIZE; // Increment total data transmitted
                double latency = total_time - start_time; // Calculate latency for this packet
                latencies.push_back(latency); // Store the latency
                total_time += 1; // Assume 1 ms for transmission time
                channel.setBusy(false); // Mark channel as idle
                packet_transmitted = true;
            } else {
                // If the channel is busy, apply a random backoff
                double backoff_time = generateRandomBackoffTime();
                total_time += backoff_time;
            }
        }
    }
}

// Calculate throughput in Mbps
double WiFi4AP::calculateThroughput() const {
    double total_seconds = total_time / 1000.0; // Convert total time from milliseconds to seconds
    return (total_data_transmitted * 8) / (total_seconds * 1'000'000); // Throughput in Mbps
}

// Calculate average latency in milliseconds
double WiFi4AP::calculateAverageLatency() const {
    if (latencies.empty()) return 0.0;
    double total_latency = std::accumulate(latencies.begin(), latencies.end(), 0.0);
    return total_latency / latencies.size();
}

// Get the maximum latency recorded
double WiFi4AP::getMaxLatency() const {
    if (latencies.empty()) return 0.0;
    return *std::max_element(latencies.begin(), latencies.end());
}
