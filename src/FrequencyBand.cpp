#include "FrequencyBand.h"

// Constructor initializes frequency band attributes
FrequencyBand::FrequencyBand(double centerFreq, double bw, const std::string& mod)
    : center_frequency(centerFreq), bandwidth(bw), modulation(mod) {}

// Returns the center frequency of the band
double FrequencyBand::getCenterFrequency() const {
    return center_frequency;
}

// Returns the bandwidth of the band
double FrequencyBand::getBandwidth() const {
    return bandwidth;
}

// Returns the modulation type
std::string FrequencyBand::getModulation() const {
    return modulation;
}
