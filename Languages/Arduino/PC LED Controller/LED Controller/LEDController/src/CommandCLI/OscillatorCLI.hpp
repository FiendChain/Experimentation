#pragma once

#include "../ICommandCLI.hpp"
#include "../LEDControllers/Oscillator.hpp"

class OscillatorCLI: public ICommandCLI
{
    private:
        Oscillator *mController;
    public:
        OscillatorCLI(Oscillator *controller);
        ResponseType ParseCommand(char *buffer, int len);
};