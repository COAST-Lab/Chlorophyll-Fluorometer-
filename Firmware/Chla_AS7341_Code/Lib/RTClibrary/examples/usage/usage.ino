// Example usage for RTClibrary library by Adafruit.

#include "RTClibrary.h"

// Initialize objects from the lib
RTClibrary rTClibrary;

void setup() {
    // Call functions on initialized library objects that require hardware
    rTClibrary.begin();
}

void loop() {
    // Use the library's initialized objects and functions
    rTClibrary.process();
}
