#include "User.h"
#include <iostream>

User::User(const std::string& deviceName, int dataUsage)
    : Device(deviceName), dataUsage(dataUsage) {}

void User::sendData(Packet* packet) {
    if (packet != nullptr) {
        std::cout << getDeviceName() << " is sending a packet of size " 
                  << packet->getPacketSize() << " to " << packet->getDestination()->getDeviceName() << std::endl;
        dataUsage += packet->getPacketSize();
    }
}

int User::getDataUsage() const {
    return dataUsage;
}

void User::setDataUsage(int usage) {
    dataUsage = usage;
}
