#include "Channel.h"

// Constructor initializes channel with a specific frequency band and sets the channel to idle
Channel::Channel(const FrequencyBand& band)
    : frequency_band(band), is_busy(false) {}

// Check if the channel is busy
bool Channel::isBusy() const {
    return is_busy;
}

// Set the channel status (busy or idle)
void Channel::setBusy(bool status) {
    is_busy = status;
}

// Get the frequency band associated with the channel
FrequencyBand Channel::getFrequencyBand() const {
    return frequency_band;
}

// Add a packet to the channel's queue
void Channel::addPacketToQueue(const Packet& packet) {
    packet_queue.push_back(packet);
}

// Get the next packet from the queue
Packet Channel::getNextPacket() {
    if (!packet_queue.empty()) {
        Packet next_packet = packet_queue.front();
        packet_queue.erase(packet_queue.begin());
        return next_packet;
    }
    throw std::runtime_error("Channel queue is empty.");
}

// Check if the queue is empty
bool Channel::isQueueEmpty() const {
    return packet_queue.empty();
}
