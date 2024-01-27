#include <math.h> // Include the math library

const int ledPin = 9; // Define the LED pin
const int frequency = 8; // Frequency of sine wave updates in milliseconds

const int shortWave[] = {
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 254, 251, 246, 239, 230, 219, 207, 193, 177, 160, 142, 123, 103, 83, 62, 41, 20, 
    0, 20, 41, 62, 83, 103, 123, 142, 160, 177, 193, 207, 219, 230, 239, 246, 251, 254,
    255, 260, 270, 280
};

const int longWave[] = {
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 254, 251, 246, 239, 230, 219, 207, 193, 177, 160, 142, 123, 103, 83, 62, 41, 20, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 41, 62, 83, 103, 123, 142, 160, 177, 193, 207, 219, 230, 239, 246, 251, 254,
    255, 255, 260, 270, 280
};

void setup() {
  pinMode(ledPin, OUTPUT); // Initialize the LED pin as an output
  Serial.begin(9600);
}

void loop() {
  sos();
  delay(2000);
}

void sos() {
  shortFlash();
  shortFlash();
  shortFlash();
  longFlash();
  longFlash();
  longFlash();
  shortFlash();
  shortFlash();
  shortFlash();
}

void shortFlashSine() {
  for (int i = 0; i < 360; i++) { // Generate sine wave values
    float radian = i * (PI / 180.0); // Convert degree to radian
    float sineVal = sin(radian); // Compute sine value
    int pwmVal = 255-(sineVal + 2) * 127.5; // Map sine value to 0-255 and above with a short flash
    Serial.println(pwmVal);
    analogWrite(ledPin, pwmVal); // Output to LED
    delay(frequency); // Wait for the next update
  }
}

void longFlashSine() {
  for (int i = 0; i < 360; i++) { // Generate sine wave values
    float radian = i * ((0.5) * PI / 180.0); // Convert degree to radian
    float sineVal = sin(radian); // Compute sine value
    int pwmVal = (sineVal + 2) * 127.5; // Map sine value to 0-255 and above with a short flash
    analogWrite(ledPin, pwmVal); // Output to LED
    delay(frequency); // Wait for the next update
  }
}

void shortFlash() {
  int arraySize = sizeof(shortWave) / sizeof(shortWave[0]);
  for (int i = 0; i < arraySize; i++) {
    analogWrite(ledPin, shortWave[i]);
    delay(25); // adjust for speed of the wave
  }
}

void longFlash() {
  int arraySize = sizeof(longWave) / sizeof(longWave[0]);
  for (int i = 0; i < arraySize; i++) {
    analogWrite(ledPin, longWave[i]);
    delay(25); // adjust for speed of the wave
  }
}