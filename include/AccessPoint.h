#ifndef ACCESSPOINT_H
#define ACCESSPOINT_H

#include "Device.h"
#include <vector>
#include <string>

// Forward declaration of User class
class User;

class AccessPoint : public Device {
protected:
    double max_backoff_time;    // Maximum backoff time for handling collisions
    std::vector<User*> connected_users;  // List of users connected to the AP
    double channel_bandwidth;   // Channel bandwidth for this Access Point

public:
    // Constructor for AccessPoint
    AccessPoint(const std::string& id, double bandwidth, const std::string& mod, double max_backoff)
        : Device(id, bandwidth, mod), max_backoff_time(max_backoff), channel_bandwidth(bandwidth) {}

    // Virtual destructor
    virtual ~AccessPoint() {}

    // Method to add a user to the Access Point's connected users
    void connectUser(User* user) { connected_users.push_back(user); }

    // Method to get the number of connected users
    size_t getConnectedUserCount() const { return connected_users.size(); }

    // Method to clear all connected users
    void disconnectAllUsers() { connected_users.clear(); }

    // Method to simulate data transmission (pure virtual, to be implemented by derived classes)
    virtual void transmitData() = 0;

    // Getter for max_backoff_time
    double getMaxBackoffTime() const { return max_backoff_time; }

    // Getter for channel bandwidth
    double getChannelBandwidth() const { return channel_bandwidth; }
};

#endif // ACCESSPOINT_H
