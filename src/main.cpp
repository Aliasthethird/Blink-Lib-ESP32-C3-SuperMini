#include <Blinker.h>

#define LED_BUILTIN 8
#define BLINK_INTERVAL 0.05f

Blinker blinker(LED_BUILTIN, BLINK_INTERVAL); // Create a Blinker object with LED pin and interval

void setup() {
    // nothing to do here
}

void loop() {
    // Main loop remains empty
}
