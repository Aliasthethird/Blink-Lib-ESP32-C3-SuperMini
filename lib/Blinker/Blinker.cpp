#include "Blinker.h"

Blinker* Blinker::activeInstance = nullptr;

Blinker::Blinker(uint8_t pin) : ledPin(pin), Timer0_Cfg(nullptr) {
    // Set the active instance to this one
    Blinker::activeInstance = this;
}

void Blinker::begin(float blinkIntervalSec) {
    pinMode(ledPin, OUTPUT);
    Timer0_Cfg = timerBegin(0, 80, true);
    timerAttachInterrupt(Timer0_Cfg, &Blinker::Timer0_ISR, true);
    timerAlarmWrite(Timer0_Cfg, secondsToMicroseconds(blinkIntervalSec), true);
    timerAlarmEnable(Timer0_Cfg);
}

void IRAM_ATTR Blinker::Timer0_ISR()
{
    if (Blinker::activeInstance) // Check if the active instance is not a nullptr
    {
        digitalWrite(Blinker::activeInstance->ledPin, !digitalRead(Blinker::activeInstance->ledPin));
    }
}
