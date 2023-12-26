#include <Blinker.h>

#define LED_BUILTIN 8
#define BLINK_INTERVAL 1.0f

Blinker blinker(LED_BUILTIN); // Create a Blinker object

void setup() {
    blinker.begin(BLINK_INTERVAL); // Initialize the blinker
}

void loop() {
    // Main loop remains empty
}
