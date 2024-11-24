#ifndef FREQUENCYBAND_H
#define FREQUENCYBAND_H

#include <string>

class FrequencyBand {
public:
    FrequencyBand(const std::string& band, int bandwidth, int range);

    void checkBandwidth() const;  // Display the bandwidth of the current frequency band
    void switchBand(const std::string& newBand);  // Switch to a different frequency band

    const std::string& getBand() const;  // Get the current frequency band
    int getBandwidth() const;  // Get the bandwidth of the frequency band
    int getRange() const;  // Get the range of the frequency band

private:
    std::string band;  // The frequency band (e.g., "2.4GHz", "5GHz")
    int bandwidth;  // The bandwidth of the frequency band in MHz
    int range;  // The range of the frequency band in meters
};

#endif // FREQUENCYBAND_H
