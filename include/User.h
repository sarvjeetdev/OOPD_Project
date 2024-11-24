#ifndef USER_H
#define USER_H

#include "Device.h"
#include "Packet.h"

class User : public Device {
public:
    User(const std::string& deviceName, int dataUsage = 0);

    void sendData(Packet* packet);  // Send data to the destination
    int getDataUsage() const;  // Get the total data usage of the user
    void setDataUsage(int usage);  // Set the total data usage for the user

private:
    int dataUsage;  // Data usage in bytes or packets sent
};

#endif // USER_H
