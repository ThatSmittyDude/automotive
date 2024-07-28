#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define UPDATE_INTERVAL_MS 1000 // 1 second in milliseconds
#define PULSES_PER_METER 10     // Number of pulses per meter

volatile uint32_t elapsedTime = 0; // Elapsed time in milliseconds
volatile bool updateSpeed = false;
volatile uint32_t pulseCount = 0;  // Count of pulses in the current interval
long currentSpeed = 0;             // Current speed in meters per second

// Simulated function to get pulse count from the sensor
void readPulseCount() {
    // Replace with actual sensor reading logic
    // For simulation, we'll just increment the pulse count
    pulseCount += PULSES_PER_METER * 16 / UPDATE_INTERVAL_MS; // Simulate a speed of 16 m/s
}

// Function to calculate speed based on pulse count
long calculateSpeed(uint32_t pulses, uint32_t interval_ms) {
    // Speed in meters per second
    return pulses * 1000 / PULSES_PER_METER / interval_ms;
}

// Dummy function to simulate displaying the speed
void displaySpeed(long speed) {
    // Replace with actual display logic
    printf("Current Speed: %ld m/s\n", speed);
}

// Timer interrupt handler (simulated for this example)
void timerInterruptHandler() {
    elapsedTime += UPDATE_INTERVAL_MS;
    if (elapsedTime >= UPDATE_INTERVAL_MS) {
        updateSpeed = true;
        elapsedTime = 0;
    }
}

int main() {
    while (1) {
        // Simulate timer interrupt
        timerInterruptHandler();

        // Simulate reading pulse count from the sensor
        readPulseCount();

        if (updateSpeed) {
            updateSpeed = false;

            // Calculate the current speed in m/s
            currentSpeed = calculateSpeed(pulseCount, UPDATE_INTERVAL_MS);

            // Reset pulse count for the next interval
            pulseCount = 0;

            // Display the current speed
            displaySpeed(currentSpeed);
        }

        // Add a delay or sleep here in a real embedded system
        // to avoid busy-waiting. This is just for simulation.
    }

    return 0;
}
