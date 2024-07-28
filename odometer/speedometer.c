#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#DEFINE UPDATE_INTERVAL_MS_1000 // Update Every second

volatile uint32_t elapsedTime = 0; // Elapsed time in milliseconds
volatile bool updateSpeed = false;
long currentSpeed = 0; //Cuurent speed in meters per second

// Dummy function to simulate getting the current speed from a sensor (m/s)
long getSpeed(){
	// Replace with actual sensor reading logic
	return 16; // Example: 16 m/s (57.6 km/h)
}

// Dummy function to simulate displaying the speed
void displaySpeed(long speed) {
	// Replace with actual display logic
	printf("Speed: %ld \n", speed);
}

// Timer interrupt handler (simulated for this example)
void timerInterruptHandler(){
	elapsedTime += UPDATE_INTERVAL_MS_1000;
	if (elapsedTime >= UPDATE_INTERVAL_MS_1000){
		updateSpeed = true;
		elapsedTime = 0;
	}
}

int main(){
	while(1){
		// Simulate timer interrupt
		timerInterruptHandler();

	if (updateSpeed){
		updateSpeed = false;

		// Get current speed in m/s
		currentSpeed =getSpeed();

		// Display the current speed
		displaySpeed(currentSpeed);
	}

	/* Add a delay or sleep here in a real embedded system
	to avoid busy waiting*/

	}
	return 0;
}
