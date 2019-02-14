#include "Pins.h"
#include <stdio.h>
#include <stdlib.h>

Pin::Pin() {
    setMode(DISABLED);
    value = 0;
}

Pin::Pin(PinMode _mode) {
    setMode(_mode);
    value = 0;
}

// set and get value
int Pin::getValue() {
    return value;
}

void Pin::setValue(int _value) {
    if(_value < MIN_OUT_PIN) {
        _value = MIN_OUT_PIN;
    }
    if(_value > MAX_OUT_PIN) {
        _value = MAX_OUT_PIN;
    }
    value = _value;
}

void Pin::setMode(PinMode _mode) {
    mode = _mode;
}

// arduino functions
void Pin::analogWrite(int _value) {
    _value = _value * MAX_OUT_PIN / (float)MAX_IN_PIN;
    setValue(_value);
}

void Pin::digitalWrite(int _value) {
    if(_value <= 0) {
        setValue(MIN_OUT_PIN);
    } else {
        setValue(MAX_OUT_PIN);
    }
}

int Pin::analogRead() {
    return getValue();
}

int Pin::digitalRead() {
    int _value = getValue();
    if(_value <= 0) return 0;
    else            return 1;
}

