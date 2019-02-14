#ifndef _ARDUINO_H_
#define _ARDUINO_H_
// special pin names analog
#define A0 14
#define A1 15
#define A2 16
#define A3 17
#define A4 18

#include "Pins.h"
#include <vector> 


class Arduino {
    public:
        Arduino(int totalPins);
        // pin operations
        void analogWrite(int pin, int value);
        void digitalWrite(int pin, int value);
        int analogRead(int pin);
        int digitalRead(int pin);
        void pinMode(int pin, PinMode mode);
        // other
        long millis();
        void delay(long duration);
        void microDelay(long micro);
    private:
        int checkPin(int pin);
        std::vector<Pin> pins;
        long startTime;     // in millis
        long delayTime;     // in millis
};

#endif