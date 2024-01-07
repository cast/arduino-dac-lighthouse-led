#include <math.h> // Include the math library

const int ledPin = 9; // Define the LED pin
const int frequency = 8; // Frequency of sine wave updates in milliseconds

void setup() {
  pinMode(ledPin, OUTPUT); // Initialize the LED pin as an output
}

void loop() {
  for (int i = 0; i < 360; i++) { // Generate sine wave values
    float radian = i * (PI / 180.0); // Convert degree to radian
    float sineVal = sin(radian); // Compute sine value
    int pwmVal = (sineVal + 1) * 127.5; // Map sine value to 0-255
    analogWrite(ledPin, pwmVal); // Output to LED
    delay(frequency); // Wait for the next update
  }
}