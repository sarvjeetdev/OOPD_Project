#include "WiFi6AP.h"
#include "Packet.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include <fstream>




WiFi6AP::WiFi6AP(const std::string& ssid, int bandwidth)
    : AccessPoint(ssid, bandwidth) {
    // WiFi 6 transmission rate calculation
    transmissionRate = bandwidth * 8 * 10e6 / 6;  // Adjusted for 256-QAM and 5/6 coding rate
    totalData = 0;
    totalTime = 0;
    maxLatency = 0;
    avgLatency = 0;
}

void WiFi6AP::simulateCommunication(int numUsers) {
    std::cout << "Simulation starting for " << numUsers << " users...\n";

    // Create devices and simulate transmission
    std::vector<Device*> devices;
    for (int i = 0; i < numUsers; ++i) {
        Device* userDevice = new Device("User_" + std::to_string(i + 1));
        devices.push_back(userDevice);
    }

    // Step 1: AP sends broadcast packet
    std::cout << "Access Point sends broadcast packet.\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(5));  // Simulate broadcast packet transmission

    // Step 2: Each user sends CSI packet (200 bytes)
    for (int i = 0; i < numUsers; ++i) {
        Device* userDevice = devices[i];

        // Simulate the CSI packet creation and transmission
        Packet csiPacket(200, this, userDevice);  // 200-byte CSI packet, AP to User
        std::cout << this->getDeviceName() << " receives CSI from " << userDevice->getDeviceName() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));  // Assume each CSI packet takes 1ms to transmit
    }

    // Step 3: Transmission for each sub-channel (2 MHz, 4 MHz, 10 MHz)
    int subChannelSizes[] = {2, 4, 10};  // Sub-channel sizes in MHz
    for (int subChannel : subChannelSizes) {
        std::cout << "Starting transmission using " << subChannel << " MHz sub-channel...\n";
        auto startTime = std::chrono::high_resolution_clock::now();
        
        // Transmit data for each user on the current sub-channel
        for (int i = 0; i < numUsers; ++i) {
            Device* userDevice = devices[i];

            // Simulate data transmission for each user
            Packet dataPacket(1024, this, userDevice);  // 1 KB packet, AP to User
            std::cout << this->getDeviceName() << " sends data to " << userDevice->getDeviceName() << std::endl;
            std::cout << "Transmitting packet of size " << dataPacket.getPacketSize() << " from " 
                      << this->getDeviceName() << " to " << userDevice->getDeviceName() << std::endl;

            // Simulate transmission per user
            double transmissionTime = (dataPacket.getPacketSize() * 8) / transmissionRate;  // Transmission time in seconds
            int maxSleepTime = 100;  // Limit the maximum sleep time to 100 ms
            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(std::min(transmissionTime * 1000.0, static_cast<double>(maxSleepTime))))); // Simulate transmission time

            totalData += dataPacket.getPacketSize();  // Increase the transmitted data

            // Calculate latency for the current user
            double latency = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - startTime).count();
            if (latency > maxLatency) {
                maxLatency = latency;  // Update maximum latency if needed
            }
        }

        auto endTime = std::chrono::high_resolution_clock::now();
        double subChannelLatency = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
        totalTime += subChannelLatency;

        std::cout << "Completed " << subChannel << " MHz sub-channel transmission.\n";
    }

    std::cout << "Simulation completed.\n";
}

// Calculate throughput, average latency, and maximum latency
void WiFi6AP::calculateMetrics(int numUsers) {
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
        logFile << "WiFi 6," << numUsers << "," << throughput << "," << avgLatency << "," << maxLatency << "\n";
        logFile.close(); // Close the file
        std::cout << "Logged Successfully.\n";
    } else {
        std::cerr << "Error opening the log file!" << std::endl;
    }
}
