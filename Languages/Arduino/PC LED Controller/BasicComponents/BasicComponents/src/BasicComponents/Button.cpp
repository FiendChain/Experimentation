#include "Button.hpp"
#include "Arduino.h"

namespace bc
{

Button::Button()
    : m_Pin(-1)
{
    SetPin(-1);    
}

Button::Button(int pin)
    : m_Pin(pin)
{
    SetPin(pin);
}

void Button::SetPin(int pin)
{
    m_Pin = pin;
    if (pin >= 0)
        pinMode(pin, INPUT_PULLUP);
}

bool Button::GetState() {
    if (m_Pin < 0)
        return false;
    return !digitalRead(m_Pin);
}

}