#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>

using namespace std;

// Function to display the time in HH:MM:SS format
void displayTime(int seconds) {
    int hours = seconds / 3600;
    int minutes = (seconds % 3600) / 60;
    int secs = seconds % 60;
    cout << "\r" << setw(2) << setfill('0') << hours << ":"
         << setw(2) << setfill('0') << minutes << ":"
         << setw(2) << setfill('0') << secs << flush;
}

int main() {
    int totalTime;

    // Get the countdown time from the user
    cout << "Enter the countdown time in seconds: ";
    cin >> totalTime;

    // Ensure the user enters a valid time
    if (totalTime < 0) {
        cout << "Invalid time. Please enter a positive number." << endl;
        return 1;
    }

    // Countdown loop
    while (totalTime >= 0) {
        displayTime(totalTime);
        this_thread::sleep_for(chrono::seconds(1)); // Wait for 1 second
        totalTime--;
    }

    // Display final message
    cout << "\nTime's up!" << endl;

    return 0;
}
