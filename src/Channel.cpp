#include "Channel.h"
#include <iostream>

Channel::Channel(const std::string& frequencyBand)
    : frequencyBand(frequencyBand), noiseLevel(0) {}

void Channel::addNoise(int noise) {
    noiseLevel += noise;
    std::cout << "Added noise of level " << noise << " to " << frequencyBand << " band." << std::endl;
}

int Channel::getSignalStrength() const {
    return 100 - noiseLevel;  // The signal strength decreases with more noise
}

const std::string& Channel::getFrequencyBand() const {
    return frequencyBand;
}
