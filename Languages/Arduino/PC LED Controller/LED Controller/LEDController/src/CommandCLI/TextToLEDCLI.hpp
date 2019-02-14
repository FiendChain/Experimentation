#pragma once

#include "../ICommandCLI.hpp"
#include "../LEDControllers/TextToLED/TextToLED.hpp"

class TextToLEDCLI: public ICommandCLI
{
    private:
        TextToLED *mController;
    public:
        TextToLEDCLI(TextToLED *controller);
        ResponseType ParseCommand(char *buffer, int len);
};