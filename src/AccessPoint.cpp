#include "AccessPoint.h"
#include "User.h"

// Constructor initializes the Access Point with its unique ID, bandwidth, modulation, and backoff settings
AccessPoint::AccessPoint(const std::string& id, double bandwidth, const std::string& mod, double max_backoff)
    : Device(id, bandwidth, mod), max_backoff_time(max_backoff), channel_bandwidth(bandwidth) {}

// Virtual destructor
AccessPoint::~AccessPoint() {
    // Cleanup if necessary when an AccessPoint is destroyed
    disconnectAllUsers();
}

// Adds a user to the list of connected users
void AccessPoint::connectUser(User* user) {
    connected_users.push_back(user);
}

// Returns the number of users currently connected to the Access Point
size_t AccessPoint::getConnectedUserCount() const {
    return connected_users.size();
}

// Clears the list of connected users
void AccessPoint::disconnectAllUsers() {
    connected_users.clear();
}

// Pure virtual function transmitData will be implemented by derived classes (WiFi4AP, WiFi5AP, etc.)
