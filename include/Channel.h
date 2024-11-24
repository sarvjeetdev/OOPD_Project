#ifndef CHANNEL_H
#define CHANNEL_H

#include <string>

class Channel {
public:
    Channel(const std::string& frequencyBand);

    void addNoise(int noise);  // Add noise to the channel, affecting signal quality
    int getSignalStrength() const;  // Get the signal strength after noise interference
    const std::string& getFrequencyBand() const;  // Get the frequency band of the channel

private:
    std::string frequencyBand;  // Frequency band (e.g., "2.4GHz", "5GHz")
    int noiseLevel;  // Noise level that affects signal strength
};

#endif // CHANNEL_H
