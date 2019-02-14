#include "OscillatorCLI.hpp"
#include "Arduino.h"
#include <stdlib.h>
#include <string.h>

OscillatorCLI::OscillatorCLI(Oscillator *controller)
    : mController(controller)
{

}

ResponseType OscillatorCLI::ParseCommand(char *buffer, int len)
{
    if (strncmp(buffer, "help", 4) == 0)
    {
        Serial.println(F("setspeed %d   \tSet speed of oscillation"));
        Serial.println(F("getspeed      \tGet speed of oscillation"));
        Serial.println(F("setrange %d %d\tSet range of oscillation"));
        Serial.println(F("getrange      \tGet range of oscillation"));
        return ACCEPTED;
    }
    // get speed
    if (strncmp(buffer, "getspeed", 8) == 0)
    {
        Serial.print(F("Oscillator speed is "));
        Serial.println(mController->GetSpeed());
        return ACCEPTED;
    }
    // get range
    if (strncmp(buffer, "getrange", 8) == 0)
    {
        Serial.print(F("Oscillator range is "));
        Serial.print(mController->GetMin());
        Serial.print(F("..."));
        Serial.println(mController->GetMax());
        return ACCEPTED;
    }
    // change speed
    int speed;
    if (sscanf(buffer, "setspeed %d", &speed) == 1)
    {
        mController->SetSpeed(speed); 
        return DATA_CHANGED;
    }
    // change range
    int min, max;
    if (sscanf(buffer, "setrange %d %d", &min, &max) == 2)
    {
        mController->SetRange(min, max);
        return DATA_CHANGED;
    }
    return REJECTED;
}