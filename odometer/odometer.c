#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define UPDATE_INTERVAL_MS_1000 // Update every second
#define MS_IN_AN_HOUR 3600000 // Number of miliseconds in an hour

volatile uint32_t elapsedTime = 0; // Elapsed time in milliseconds
volatile bool updateOdometer = false;
long totalDistance = 0; // Total Distance in meters

// Dummy Function to simulate getting the current speed from sensor in (m/s)
long getSpeed(){
	// Replace with actual sensor reading logic
	return 16; // Example: 16 m/s (57.6 km/h)
}

// Dummy Function to simulate displaying the odometer reading
void displayOdometerReading(long distance){
	// Replace with actual display logic
	printf("Odometer: %ld \n", distance);
}

// Timer interrupt handler (simulated for this example)
void timerInterruptHandler(){
	elapsedTime += UPDATE_INTERVAL_MS_1000;
	if (elapsedTime >= UPDATE_INTERVAL_MS_1000){
		updateOdometer = true;
		elapsedTime = 0;
	}
}

int main(){
	while(1){
		// Simulate timer interrupt
		timerInterruptHandler();

		if (updateOdometer){
			updateOdometer = false;

			// Get current speed in m/s
			long currentSpeed = getSpeed();

			// Calculated the distance covered (distance = speed * time)
			//Time is in seconds (UPDATE_INTERVAL_MS / 1000)
			long distanceCovered = currentSpeed * (UPDATE_INTERVAL_MS_1000 / 1000);

			// Update total distance
			totalDistance += distanceCovered;

			// Display upodated odometer reading
			displayOdometerReading(totalDistance);
		}

		/* Add a delay for sleep here in a real embedded system
		to avoid busy-waiting. This is just for simualtion */
	}
	return 0;
}
