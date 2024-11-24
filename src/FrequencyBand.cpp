#include "FrequencyBand.h"
#include <iostream>

FrequencyBand::FrequencyBand(const std::string& band, int bandwidth, int range)
    : band(band), bandwidth(bandwidth), range(range) {}

void FrequencyBand::checkBandwidth() const {
    std::cout << "Bandwidth for " << band << " is " << bandwidth << " MHz." << std::endl;
}

void FrequencyBand::switchBand(const std::string& newBand) {
    band = newBand;
    std::cout << "Switched to the " << band << " frequency band." << std::endl;
}

const std::string& FrequencyBand::getBand() const {
    return band;
}

int FrequencyBand::getBandwidth() const {
    return bandwidth;
}

int FrequencyBand::getRange() const {
    return range;
}
