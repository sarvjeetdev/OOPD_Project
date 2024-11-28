#include "WiFi4AP.h"
#include "Packet.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include <fstream>






WiFi4AP::WiFi4AP(const std::string& ssid, int bandwidth)
    : AccessPoint(ssid, bandwidth) {
    // Calculate the transmission rate based on modulation and coding rate
    transmissionRate = bandwidth * 8 / 6;  // 20 MHz * 8 bits / 6 for 256-QAM and 5/6 coding rate
    totalData = 0;
    totalTime = 0;
    maxLatency = 0;
    avgLatency = 0;
}

void WiFi4AP::simulateCommunication(int numUsers) {
    std::cout << "Simulation starting for " << numUsers << " users...\n";

    // Set up random number generator for backoff time
    std::default_random_engine generator;
    std::uniform_int_distribution<int> backoffDistribution(0, 10);  // Random backoff between 0 and 10 ms
    std::uniform_int_distribution<int> channelStateDistribution(0, 1);  // Channel state (0 = busy, 1 = free)

    // Create devices and simulate transmission
    for (int i = 0; i < numUsers; ++i) {
        Device* userDevice = new Device("User_" + std::to_string(i + 1));
        devices.push_back(userDevice);

        // Simulate the packet creation and transmission
        Packet packet(1024, this, userDevice);  // 1 KB packet, AP to User
        std::cout << this->getDeviceName() << " sends data to " << userDevice->getDeviceName() << std::endl;

        bool channelFree = false;  // Assume channel is busy initially
        int retries = 0;
        int contentionWindow = 10;  // Initial contention window (max backoff time)
        double startTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        double latency = 0;

        while (true) {  // Keep trying until the packet is successfully transmitted
            // Randomly simulate if the channel is free or busy
            channelFree = (channelStateDistribution(generator) == 1);

            if (channelFree) {
                // Simulate data transmission
                std::cout << "Transmitting packet of size " << packet.getPacketSize()
                          << " from " << this->getDeviceName() << " to " << userDevice->getDeviceName() << std::endl;

                double transmissionTime = (packet.getPacketSize() * 8) / transmissionRate;  // Transmission time in seconds
                int maxSleepTime = 100;  // Limit the maximum sleep time to 100 ms

                // Sleep for the transmission time, but limit it to a reasonable upper bound (100 ms)
                std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(std::min(transmissionTime * 1000.0, static_cast<double>(maxSleepTime))))); // cast both arguments to double

                totalData += packet.getPacketSize();  // Increase the transmitted data
                latency = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - startTime;
                if (latency > maxLatency) {
                    maxLatency = latency;
                }
                totalTime += latency;
                break;  // Successful transmission, exit the retry loop
            } else {
                // Simulate backoff if the channel is busy
                int backoffTime = backoffDistribution(generator) * contentionWindow;  // Random backoff time, based on current contention window
                std::cout << "Channel busy, backing off for " << backoffTime << " ms...\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(backoffTime));

                retries++;  // Retry after backoff
                // Increase the contention window to simulate exponential backoff
                contentionWindow = std::min(contentionWindow * 2, 100);  // Cap the contention window at 100 ms
            }
        }
    }

    std::cout << "Simulation completed.\n";
}

void WiFi4AP::calculateMetrics(int numUsers) {
    avgLatency = totalTime / numUsers;  // Average latency in ms
    double throughput = totalData / totalTime;  // Throughput in KB/ms

    // Output to the console
    std::cout << "Throughput: " << throughput << " KB/ms" << std::endl;
    std::cout << "Average Latency: " << avgLatency << " ms" << std::endl;
    std::cout << "Maximum Latency: " << maxLatency << " ms" << std::endl;

    // Log the results to a CSV file
    std::ofstream logFile("./data/logFile.csv", std::ios::app); // Open file in append mode

    if (logFile.is_open()) {
        
        // Log the data
        logFile << "WiFi 4," << numUsers << "," << throughput << "," << avgLatency << "," << maxLatency << "\n";
        logFile.close(); // Close the file
        std::cout << "Logged Successfully.\n";
    } else {
        std::cerr << "Error opening the log file!" << std::endl;
    }
}
