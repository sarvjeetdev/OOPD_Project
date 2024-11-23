#include "Packet.h"

// Constructor initializes packet attributes
Packet::Packet(int size, const std::string& source, const std::string& destination, double time, bool ack)
    : packet_size(size), source_id(source), destination_id(destination), timestamp(time), ack_required(ack) {}

// Returns the size of the packet
int Packet::getSize() const {
    return packet_size;
}

// Returns the source ID of the packet
std::string Packet::getSourceId() const {
    return source_id;
}

// Returns the destination ID of the packet
std::string Packet::getDestinationId() const {
    return destination_id;
}

// Returns the timestamp of the packet
double Packet::getTimestamp() const {
    return timestamp;
}

// Checks if the packet requires an acknowledgment
bool Packet::isAckRequired() const {
    return ack_required;
}
