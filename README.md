# WiFi Simulator Project

## Overview
This project simulates WiFi communication using three different WiFi standards: WiFi 4 (802.11n), WiFi 5 (802.11ac), and WiFi 6 (802.11ax). The simulation models various aspects of these standards including transmission rates, latency, throughput, and channel access techniques. The user can simulate the behavior of each WiFi standard with varying numbers of users and observe the metrics for throughput, average latency, and maximum latency.

## Features
- **WiFi 4 Simulation**: Supports CSMA/CA with backoff periods for 1, 10, and 100 users.
- **WiFi 5 Simulation**: Models MU-MIMO and parallel communication for 1, 10, and 100 users.
- **WiFi 6 Simulation**: Simulates OFDMA with sub-channel allocation for 1, 10, and 100 users.
- **Dynamic Simulation**: Users can run multiple simulations without restarting the program, with options for WiFi 4, WiFi 5, and WiFi 6.

## Requirements
- C++11 or higher compiler.
- Standard C++ libraries (No external libraries required).
- Makefile utility. 

## How to Run

1. Clone this repository to your local machine:
2. Run the following command. 
   ```bash
   make
   ./project
   ```


References
WiFi 4 (802.11n): Wi-Fi Alliance - Wi-Fi 4 (802.11n)
WiFi 5 (802.11ac): Wi-Fi Alliance - Wi-Fi 5 (802.11ac)
WiFi 6 (802.11ax): Wi-Fi Alliance - Wi-Fi 6 (802.11ax)


I have used ChatGPT for Project Assistance. 
