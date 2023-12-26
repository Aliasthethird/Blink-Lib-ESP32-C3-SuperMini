#ifndef Blinker_h
#define Blinker_h

#include <Arduino.h>

class Blinker {
public:
    Blinker(uint8_t pin);
    void begin(float blinkIntervalSec);
    static void IRAM_ATTR Timer0_ISR();

    static Blinker *activeInstance; // Pointer to the active instance

private:
    uint8_t ledPin;
    hw_timer_t *Timer0_Cfg;

    static constexpr uint64_t secondsToMicroseconds(float s) {
        return static_cast<uint64_t>(s * 1000000);
    }
};

#endif
