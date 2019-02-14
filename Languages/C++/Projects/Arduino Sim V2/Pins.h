#ifndef _PINS_H_
#define _PINS_H_
#define MIN_OUT_PIN 0
#define MAX_OUT_PIN 255
#define MIN_IN_PIN 0
#define MAX_IN_PIN 1023


typedef enum {
    INPUT, OUTPUT, DISABLED,
} PinMode;

class Pin {
    public:
        Pin();
        Pin(PinMode _mode);
        // arduino functions
        void analogWrite(int _value);
        void digitalWrite(int _value);
        int analogRead();
        int digitalRead();
        void setMode(PinMode _mode);
    private:
        PinMode mode;
        int value;
        // setters
        int getValue();
        void setValue(int _value);
};

#endif