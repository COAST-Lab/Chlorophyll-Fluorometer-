// Example usage for Adafruit_AS3741 library by Adafruit.

#include "Adafruit_AS3741.h"

// Initialize objects from the lib
Adafruit_AS3741 adafruit_AS3741;

void setup() {
    // Call functions on initialized library objects that require hardware
    adafruit_AS3741.begin();
}

void loop() {
    // Use the library's initialized objects and functions
    adafruit_AS3741.process();
}
