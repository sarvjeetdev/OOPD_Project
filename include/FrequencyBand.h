#ifndef FREQUENCYBAND_H
#define FREQUENCYBAND_H

#include <string>

class FrequencyBand {
private:
    double center_frequency;   // Center frequency of the band in MHz
    double bandwidth;          // Bandwidth in MHz (e.g., 20 MHz, 40 MHz)
    std::string modulation;    // Modulation type (e.g., 256-QAM)

public:
    // Constructor
    FrequencyBand(double centerFreq, double bw, const std::string& mod);

    // Getter for center frequency
    double getCenterFrequency() const;

    // Getter for bandwidth
    double getBandwidth() const;

    // Getter for modulation
    std::string getModulation() const;
};

#endif // FREQUENCYBAND_H
