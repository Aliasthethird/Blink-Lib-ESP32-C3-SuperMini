#ifndef Blinker_h
#define Blinker_h

#include <Arduino.h>

class Blinker
{
public:
    Blinker(uint8_t pin, float blinkIntervalSec);

private:
    uint8_t ledPin;
    float intervalSec;
    hw_timer_t *Timer0_Cfg;

    void begin();

    static constexpr uint64_t secondsToMicroseconds(float s)
    {
        return static_cast<uint64_t>(s * 1000000);
    }

public: // This is public because it is called from the ISR but it should not be called from anywhere else
    static void IRAM_ATTR Timer0_ISR();
    static Blinker *activeInstance; // Pointer to the active instance of the Blinker class
};

#endif
