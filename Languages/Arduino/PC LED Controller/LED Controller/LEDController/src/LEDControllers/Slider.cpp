#include "Slider.hpp"

Slider::Slider(int value)
    : mValue(0)
{
    SetValue(value);
}

bool Slider::SetValue(int value)
{
    if (value < 0 || value > 255)
    {
        return false;
    }
    mValue = value;
    return true;
}