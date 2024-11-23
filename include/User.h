#ifndef USER_H
#define USER_H

#include "Device.h"
#include "AccessPoint.h"
#include <string>

class User : public Device {
private:
    AccessPoint* connected_ap; // Pointer to the Access Point the user is connected to
    double data_rate;          // Data rate in Mbps for this user
    int total_packets_sent;    // Total number of packets sent by this user
    int total_packets_received; // Total number of packets received by this user

public:
    // Constructor for User
    User(const std::string& id, double bandwidth, const std::string& mod, double rate)
        : Device(id, bandwidth, mod), connected_ap(nullptr), data_rate(rate),
          total_packets_sent(0), total_packets_received(0) {}

    // Method to connect to an Access Point
    void connectToAP(AccessPoint* ap);

    // Method to disconnect from the current Access Point
    void disconnectFromAP();

    // Method to check if the user is connected to an Access Point
    bool isConnected() const { return connected_ap != nullptr; }

    // Method to get the data rate of the user
    double getDataRate() const { return data_rate; }

    // Getter for total packets sent
    int getTotalPacketsSent() const { return total_packets_sent; }

    // Getter for total packets received
    int getTotalPacketsReceived() const { return total_packets_received; }

    // Override methods from Device for sending and receiving data
    void sendData() override;
    void receiveData() override;

    // Method to simulate data transmission for testing
    void simulateTransmission(int num_packets);

    // Destructor
    ~User() override;
};

#endif // USER_H
