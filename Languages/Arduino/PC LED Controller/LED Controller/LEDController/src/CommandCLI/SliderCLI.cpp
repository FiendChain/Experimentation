#include "SliderCLI.hpp"
#include <string.h>
#include <stdlib.h>
#include <Arduino.h>

SliderCLI::SliderCLI(Slider *slider)
    : mSlider(slider)
{

}

ResponseType SliderCLI::ParseCommand(char *buffer, int len)
{
    if (strncmp(buffer, "help", 4) == 0)
    {
        Serial.println(F("setvalue %d\tSet brightness of led"));
        Serial.println(F("getvalue   \tGet current brightness of led"));
        return ACCEPTED;
    } 
    if (strncmp(buffer, "getvalue", 8) == 0)
    {
        Serial.print(F("Slider value is "));
        Serial.println(mSlider->GetValue());
        return ACCEPTED;
    }
    int value;
    if (sscanf(buffer, "setvalue %d", &value) == 1)
    {
        if (!mSlider->SetValue(value))
        {
            Serial.println("Invalid value for slider");
            return ACCEPTED;
        }
        return DATA_CHANGED;
    }
    return REJECTED;
}