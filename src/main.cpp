#include <iostream>
#include "WiFi4AP.h"
#include "WiFi5AP.h"
#include "WiFi6AP.h"
#include "Device.h"

using namespace std;

void simulate_wifi5() {
    WiFi5AP wifi5("WiFi5_SSID", 20);  // Create a WiFi 5 access point with 20 MHz bandwidth

    cout << "\n--- Simulating WiFi 5 ---\n";
    // Simulate communication for 1 user, 10 users, and 100 users
    wifi5.simulateCommunication(1);
    wifi5.calculateMetrics(1);
    cout << "\n";
    wifi5.simulateCommunication(10);
    wifi5.calculateMetrics(10);
    cout << "\n";
    wifi5.simulateCommunication(100);
    wifi5.calculateMetrics(100);
}

void simulate_wifi4() {
    WiFi4AP wifi4("WiFi4_SSID", 20);  // Create a WiFi 4 access point with 20 MHz bandwidth

    cout << "\n--- Simulating WiFi 4 ---\n";
    // Simulate communication for 1 user, 10 users, and 100 users
    wifi4.simulateCommunication(1);
    wifi4.calculateMetrics(1);
    cout << "\n";
    wifi4.simulateCommunication(10);
    wifi4.calculateMetrics(10);
    cout << "\n";
    wifi4.simulateCommunication(100);
    wifi4.calculateMetrics(100);
}

void simulate_wifi6() {
    WiFi6AP wifi6("WiFi6_SSID", 20);  // Create a WiFi 6 access point with 20 MHz bandwidth

    cout << "\n--- Simulating WiFi 6 ---\n";
    // Simulate communication for 1 user, 10 users, and 100 users
    wifi6.simulateCommunication(1);
    wifi6.calculateMetrics(1);
    cout << "\n";
    wifi6.simulateCommunication(10);
    wifi6.calculateMetrics(10);
    cout << "\n";
    wifi6.simulateCommunication(100);
    wifi6.calculateMetrics(100);
}

int get_valid_input() {
    int choice;
    while (true) {
        cout << "\nChoose the WiFi simulation to run:\n";
        cout << "1. WiFi 4 (802.11n)\n";
        cout << "2. WiFi 5 (802.11ac)\n";
        cout << "3. WiFi 6 (802.11ax)\n";
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        // Handle invalid input
        if (cin.fail() || choice < 1 || choice > 3) {
            cin.clear();  // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore the rest of the input
            cout << "Invalid input. Please enter a number between 1 and 3.\n";
        } else {
            return choice;
        }
    }
}

int main() {
    cout << "------------ WiFi Simulation Program ------------\n";

    bool runAgain = true;
    while (runAgain) {
        int choice = get_valid_input();

        switch (choice) {
            case 1:
                simulate_wifi4();
                break;
            case 2:
                simulate_wifi5();
                break;
            case 3:
                simulate_wifi6();
                break;
            default:
                cout << "Invalid choice! Exiting program.\n";
                break;
        }

        // Ask user if they want to simulate another WiFi version
        char userChoice;
        cout << "Do you want to simulate another WiFi version? (y/n): ";
        cin >> userChoice;

        if (userChoice != 'y' && userChoice != 'Y') {
            runAgain = false;
            cout << "Exiting program. Goodbye!\n";
        }
    }

    return 0;
}
