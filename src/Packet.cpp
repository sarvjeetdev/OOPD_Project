#include "Packet.h"
#include <iostream>

Packet::Packet(int packetSize, Device* source, Device* destination)
    : packetSize(packetSize), source(source), destination(destination) {}

int Packet::getPacketSize() const {
    return packetSize;
}

Device* Packet::getSource() const {
    return source;
}

Device* Packet::getDestination() const {
    return destination;
}

void Packet::transmit() {
    if (source != nullptr && destination != nullptr) {
        std::cout << "Transmitting packet of size " << packetSize 
                  << " from " << source->getDeviceName() 
                  << " to " << destination->getDeviceName() << std::endl;
    }
}
