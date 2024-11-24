#ifndef PACKET_H
#define PACKET_H

#include "Device.h"

class Packet {
public:
    Packet(int packetSize, Device* source, Device* destination);

    int getPacketSize() const;  // Get the size of the packet
    Device* getSource() const;  // Get the source device
    Device* getDestination() const;  // Get the destination device

    void transmit();  // Simulate packet transmission

private:
    int packetSize;  // Size of the packet
    Device* source;  // Source device sending the packet
    Device* destination;  // Destination device receiving the packet
};

#endif // PACKET_H
