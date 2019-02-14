#include "Arduino.h"
#include <time.h>

Arduino::Arduino(int totalPins):
pins(totalPins),
startTime(time())
{

}

int Arduino::checkPin(int pin) {
    if(pin < 0) return 0;
    if(pin >= pins.size()) return 0;
    return 1;
}

void Arduino::analogWrite(int pin, int value) {
    if(checkPin(pin)) {
        pins.at(pin).analogWrite(value);
    }
}

void Arduino::digitalWrite(int pin, int value) {
    if(checkPin(pin)) {
        pins.at(pin).digitalWrite(value);
    }
}

int Arduino::analogRead(int pin) {
    if(checkPin(pin)) {
        return pins.at(pin).analogRead();
    }
    return 0;
}

int Arduino::digitalRead(int pin) {
    if(checkPin(pin)) {
        return pins.at(pin).digitalRead();
    }
    return 0;
}

void Arduino::pinMode(int pin, PinMode mode) {
    if(checkPin(pin)) {
        pins.at(pin).setMode(mode);
    }
}

// time stuff
long Arduino::millis() {
    return time()-startTime;
}

// delay
void Arduino::delay(long duration) {
    if(duration < 0) return;
    delayTime = duration;
}

void Arduino::microDelay(long micro) {
    
}


