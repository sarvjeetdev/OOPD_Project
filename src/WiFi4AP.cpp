#include "WiFi4AP.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <random>

WiFi4AP::WiFi4AP(const std::string& ssid, int bandwidth)
    : AccessPoint(ssid, bandwidth) {
    // Calculate the transmission rate based on modulation and coding rate
    transmissionRate = bandwidth * 8 * 10e6 / 6;  // 20 MHz * 8 bits / 6 for 256-QAM and 5/6 coding rate
    totalData = 0;
    totalTime = 0;
    maxLatency = 0;
    avgLatency = 0;
}

// Simulate the transmission for the given number of users
void WiFi4AP::simulateCommunication(int numUsers) {
    std::cout << "Simulation starting for " << numUsers << " users...\n";

    // Set up random number generator for backoff time
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, 5);  // Random backoff between 0 and 5 ms (upper bound)

    for (int i = 0; i < numUsers; ++i) {
        Device* userDevice = new Device("User_" + std::to_string(i + 1));
        devices.push_back(userDevice);

        // Simulate transmission process for each device
        bool channelFree = true;  // Assume channel is free initially
        int retries = 0;
        double startTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        double latency = 0;

        while (retries < 5) {  // Retry up to 5 times
            if (channelFree) {
                // Simulate data transmission (with fixed time for demo purposes)
                double transmissionTime = 5.0;  // Fixed transmission time of 5ms for the demo
                std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(transmissionTime)));

                totalData += 1024;  // Increase the transmitted data
                latency = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - startTime;
                if (latency > maxLatency) {
                    maxLatency = latency;
                }
                totalTime += latency;
                break;
            } else {
                // Simulate backoff if the channel is busy (with fixed backoff time)
                int backoffTime = distribution(generator);  // Random backoff time in ms (between 0 and 5 ms)
                std::this_thread::sleep_for(std::chrono::milliseconds(backoffTime));
            }
            retries++;
        }
    }

    std::cout << "Simulation completed.\n";
}

// Calculate throughput, average latency, and maximum latency
void WiFi4AP::calculateMetrics(int numUsers) {
    float throughput = totalData / totalTime;  // Throughput in KB/ms

    avgLatency = totalTime / numUsers;  // Average latency in ms

    std::cout << "Throughput: " << throughput << " KB/ms" << std::endl;
    std::cout << "Average Latency: " << avgLatency << " ms" << std::endl;
    std::cout << "Maximum Latency: " << maxLatency << " ms" << std::endl;
}
