#include "WiFi5AP.h"
#include "Packet.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include <fstream>



WiFi5AP::WiFi5AP(const std::string& ssid, int bandwidth)
    : AccessPoint(ssid, bandwidth) {
    // Calculate the transmission rate based on modulation and coding rate
    transmissionRate = bandwidth * 8 * 10e6 / 6;  // Adjusted for 256-QAM and 5/6 coding rate
    totalData = 0;
    totalTime = 0;
    maxLatency = 0;
    avgLatency = 0;
}

void WiFi5AP::simulateCommunication(int numUsers) {
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

    // Step 3: Round-robin scheduling for parallel communication (15 ms)
    std::cout << "Starting parallel communication for 15 ms.\n";
    auto startTime = std::chrono::high_resolution_clock::now();

    int currentIndex = 0;
    bool channelFree = true;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, 1);  // Simulate random channel states (0 = free, 1 = busy)
    
    int roundCounter = 0;  // Counter for completed rounds

    while (currentIndex < numUsers) {
        Device* userDevice = devices[currentIndex];

        // Simulate data transmission for each user
        Packet dataPacket(1024, this, userDevice);  // 1 KB packet, AP to User
        std::cout << this->getDeviceName() << " sends data to " << userDevice->getDeviceName() << std::endl;
        std::cout << "Transmitting packet of size " << dataPacket.getPacketSize() << " from " 
                  << this->getDeviceName() << " to " << userDevice->getDeviceName() << std::endl;

        // Simulate channel being busy randomly
        channelFree = true;

        if (channelFree) {
            // Simulate data transmission
            double transmissionTime = (dataPacket.getPacketSize() * 8) / transmissionRate;  // Transmission time in seconds
            int maxSleepTime = 100;  // Limit the maximum sleep time to 100 ms
            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(std::min(transmissionTime * 1000.0, static_cast<double>(maxSleepTime))))); // Simulate transmission time

            totalData += dataPacket.getPacketSize();  // Increase the transmitted data

            // Calculate latency for the current user
            double latency = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - startTime).count();
            if (latency > maxLatency) {
                maxLatency = latency;  // Update maximum latency if needed
            }
        } else {
            // Simulate backoff if the channel is busy
            int backoffTime = distribution(generator) * 10;  // Random backoff time (0-10 ms)
            std::cout << "Channel busy, backing off for " << backoffTime << " ms...\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(backoffTime));
        }

        // Simulate round-robin scheduling by moving to the next user
        currentIndex++;

        // After completing a round (all users have transmitted), wait for 15ms
        if (currentIndex == numUsers) {
            std::this_thread::sleep_for(std::chrono::milliseconds(15));  // All users send in parallel for 15ms
            currentIndex = 0;  // Reset to start again for the next round
            roundCounter++;
        }

        // Stop after 5 rounds or when all users have transmitted
        if (roundCounter >= 5) break;
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    double latency = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
    totalTime += latency;

    std::cout << "Simulation completed.\n";
}

// Calculate throughput, average latency, and maximum latency
void WiFi5AP::calculateMetrics(int numUsers) {
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
        logFile << "WiFi 5," << numUsers << "," << throughput << "," << avgLatency << "," << maxLatency << "\n";
        logFile.close(); // Close the file
        std::cout << "Logged Successfully.\n";
    } else {
        std::cerr << "Error opening the log file!" << std::endl;
    }
}
