#include "TextToLEDCLI.hpp"
#include <Arduino.h>
#include <string.h>
#include <stdlib.h>

TextToLEDCLI::TextToLEDCLI(TextToLED *controller)
    : mController(controller)
{

}

ResponseType TextToLEDCLI::ParseCommand(char *buffer, int len)
{
    if (strncmp(buffer, "help", 4) == 0)
    {
        Serial.println(F("send %s    \tSend text to encode as LED flashes"));
        Serial.println(F("stop       \tStop the current encoding"));
        Serial.println(F("resend     \tResend the last message"));
        Serial.println(F("setspeed %d\tSet period of each tick"));
        Serial.println(F("getspeed   \tGet tick period"));
        return ACCEPTED;
    }
    if (strncmp(buffer, "send ", 5) == 0)
    {
        mController->SetString(&buffer[5]);
        return ACCEPTED;
    }
    if (strncmp(buffer, "stop", 4) == 0)
    {
        mController->Stop();
        return ACCEPTED;
    }
    if (strncmp(buffer, "resend", 6) == 0)
    {
        mController->Start();
        return ACCEPTED;
    }
    if (strncmp(buffer, "getspeed", 8) == 0)
    {
        Serial.print(F("Morse tick speed is "));
        Serial.println(mController->GetTickLength());
        return ACCEPTED;
    }
    int speed;
    if (sscanf(buffer, "setspeed %d", &speed) == 1)
    {
        mController->SetTickLength(speed);
        return DATA_CHANGED;
    }
    return REJECTED;
}