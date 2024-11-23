#ifndef PACKET_H
#define PACKET_H

#include <string>

class Packet {
private:
    int packet_size;            // Size of the packet in bytes
    std::string source_id;      // ID of the device sending the packet
    std::string destination_id; // ID of the device receiving the packet
    double timestamp;           // Timestamp of when the packet was created
    bool ack_required;          // Whether acknowledgment is required for this packet

public:
    // Constructor
    Packet(int size, const std::string& source, const std::string& destination, double time, bool ack = false);

    // Getter for packet size
    int getSize() const;

    // Getter for source ID
    std::string getSourceId() const;

    // Getter for destination ID
    std::string getDestinationId() const;

    // Getter for timestamp
    double getTimestamp() const;

    // Check if acknowledgment is required
    bool isAckRequired() const;
};

#endif // PACKET_H
