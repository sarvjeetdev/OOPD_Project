#ifndef CHANNEL_H
#define CHANNEL_H

#include "FrequencyBand.h"  // Include the header file for FrequencyBand class
#include "Packet.h"         // Include the header file for Packet class
#include <vector>           // Required for std::vector
#include <stdexcept>        // Required for std::runtime_error

class Channel {
private:
    FrequencyBand frequency_band;    // Frequency band associated with this channel
    bool is_busy;                    // Status of the channel (true if busy, false if idle)
    std::vector<Packet> packet_queue; // Queue of packets waiting to be transmitted

public:
    // Constructor
    Channel(const FrequencyBand& band);

    // Method to check if the channel is busy
    bool isBusy() const;

    // Method to mark the channel as busy
    void setBusy(bool status);

    // Method to get the associated frequency band
    FrequencyBand getFrequencyBand() const;

    // Method to add a packet to the channel's queue
    void addPacketToQueue(const Packet& packet);

    // Method to get the next packet in the queue
    Packet getNextPacket();

    // Method to check if the queue is empty
    bool isQueueEmpty() const;
};

#endif // CHANNEL_H
