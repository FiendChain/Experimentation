#pragma once

#include "../ICommandCLI.hpp"
#include "../LEDControllers/Slider.hpp"

class SliderCLI: public ICommandCLI
{
    private:
        Slider *mSlider;
    public:
        SliderCLI(Slider *slider);
        ResponseType ParseCommand(char *buffer, int len);
};