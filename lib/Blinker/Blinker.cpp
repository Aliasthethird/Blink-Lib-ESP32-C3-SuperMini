#include "Blinker.h"

Blinker* Blinker::activeInstance = nullptr;

Blinker::Blinker(uint8_t pin, float blinkIntervalSec) : ledPin(pin), intervalSec(blinkIntervalSec), Timer0_Cfg(nullptr) {
    Blinker::activeInstance = this;
    Blinker::begin();
}

void Blinker::begin() {
    pinMode(ledPin, OUTPUT);
    Timer0_Cfg = timerBegin(0, 80, true);
    timerAttachInterrupt(Timer0_Cfg, &Blinker::Timer0_ISR, true);
    timerAlarmWrite(Timer0_Cfg, secondsToMicroseconds(intervalSec), true);
    timerAlarmEnable(Timer0_Cfg);
}

void IRAM_ATTR Blinker::Timer0_ISR() {
    if (Blinker::activeInstance) {
        digitalWrite(Blinker::activeInstance->ledPin, !digitalRead(Blinker::activeInstance->ledPin));
    }
}
