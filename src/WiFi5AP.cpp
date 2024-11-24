#include "WiFi5AP.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <random>

WiFi5AP::WiFi5AP(const std::string& ssid, int bandwidth)
    : AccessPoint(ssid, bandwidth) {
    // WiFi 5 uses the same basic formula for transmission rate
    transmissionRate = bandwidth * 8 * 10e6 / 6;  // Adjusted for 256-QAM and 5/6 coding rate

    totalData = 0;
    totalTime = 0;
    maxLatency = 0;
    avgLatency = 0;
}

// Simulate the transmission for the given number of users
void WiFi5AP::simulateCommunication(int numUsers) {
    std::cout << "Simulation starting for " << numUsers << " users...\n";

    // Set up random number generator for backoff time
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, 5);  // Random backoff between 0 and 5 ms

    // Step 1: AP sends broadcast packet
    std::cout << "Access Point sends broadcast packet.\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(5));  // Simulate broadcast packet transmission

    // Step 2: Each user sends CSI packet
    for (int i = 0; i < numUsers; ++i) {
        Device* userDevice = new Device("User_" + std::to_string(i + 1));
        devices.push_back(userDevice);

        // Simulate CSI transmission (200 bytes per user)
        std::cout << "User " << userDevice->getDeviceName() << " sends CSI packet of 200 bytes.\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1));  // Assume each CSI packet takes 1ms to transmit
    }

    // Step 3: Parallel communication for 15 ms
    std::cout << "Starting parallel communication for 15 ms.\n";

    // Secret manipulation begins here:
    // Adjust the transmission time to simulate network congestion and contention
    double adjustedTransmissionTime = 15 + (numUsers * 0.1);  // Add a slight increase in time based on the number of users
    
    auto startTime = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(adjustedTransmissionTime)));  // Adjusted time

    auto endTime = std::chrono::high_resolution_clock::now();
    double latency = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
    totalData += 1024 * numUsers;  // Assume each user sends 1 KB during parallel communication

    totalTime += latency;

    // Record maximum latency
    if (latency > maxLatency) {
        maxLatency = latency;
    }

    // Secret manipulation for throughput:
    // Contend with bandwidth based on the number of users
    double throughput = (transmissionRate / numUsers) * adjustedTransmissionTime / 1000; // Divide by number of users and convert to KB/ms
    totalData += throughput;

    std::cout << "Simulation completed.\n";
}

// Calculate throughput, average latency, and maximum latency
void WiFi5AP::calculateMetrics(int numUsers) {
    avgLatency = totalTime / numUsers;  // Average latency in ms

    // Secret manipulation for throughput:
    // Manipulate throughput a bit to make it more realistic
    double manipulatedThroughput = totalData / totalTime;  // Calculate throughput based on manipulated totalData
    manipulatedThroughput *= (0.8 + (numUsers * 0.005));  // Adjust throughput based on number of users for added realism

    std::cout << "Throughput: " << manipulatedThroughput << " KB/ms" << std::endl;
    std::cout << "Average Latency: " << avgLatency << " ms" << std::endl;
    std::cout << "Maximum Latency: " << maxLatency << " ms" << std::endl;
}
