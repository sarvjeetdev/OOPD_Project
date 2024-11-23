#include "User.h"
#include <iostream>

// Constructor initializes User with its unique ID, supported bandwidth, modulation, and data rate
User::User(const std::string& id, double bandwidth, const std::string& mod, double rate)
    : Device(id, bandwidth, mod), connected_ap(nullptr), data_rate(rate),
      total_packets_sent(0), total_packets_received(0) {}

// Connect to an Access Point
void User::connectToAP(AccessPoint* ap) {
    if (ap) {
        connected_ap = ap;
        ap->connectUser(this);
        std::cout << "User " << device_id << " connected to AP " << ap->getDeviceId() << "\n";
    } else {
        std::cerr << "Error: Attempted to connect to a null Access Point.\n";
    }
}

// Disconnect from the current Access Point
void User::disconnectFromAP() {
    if (connected_ap) {
        std::cout << "User " << device_id << " disconnected from AP " << connected_ap->getDeviceId() << "\n";
        connected_ap = nullptr;
    } else {
        std::cerr << "Error: User is not connected to any Access Point.\n";
    }
}

// Check if the user is connected to an Access Point
bool User::isConnected() const {
    return connected_ap != nullptr;
}

// Send data to the connected Access Point
void User::sendData() {
    if (connected_ap) {
        // Simulate sending data
        std::cout << "User " << device_id << " is sending data to AP " << connected_ap->getDeviceId() << "\n";
        total_packets_sent++;
    } else {
        std::cerr << "Error: User " << device_id << " is not connected to any Access Point.\n";
    }
}

// Receive data from the connected Access Point
void User::receiveData() {
    if (connected_ap) {
        // Simulate receiving data
        std::cout << "User " << device_id << " is receiving data from AP " << connected_ap->getDeviceId() << "\n";
        total_packets_received++;
    } else {
        std::cerr << "Error: User " << device_id << " is not connected to any Access Point.\n";
    }
}

// Simulate data transmission for testing purposes
void User::simulateTransmission(int num_packets) {
    if (isConnected()) {
        for (int i = 0; i < num_packets; ++i) {
            sendData();
            receiveData();
        }
        std::cout << "Simulation completed for " << num_packets << " packets.\n";
    } else {
        std::cerr << "Error: User " << device_id << " is not connected to any Access Point.\n";
    }
}

// Destructor
User::~User() {
    // Clean up any resources if necessary
    disconnectFromAP();
}
