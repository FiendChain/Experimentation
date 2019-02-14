#include "LED.hpp"
#include <Arduino.h>

namespace bc
{

LED::LED()
    : m_Pin(-1),
      m_Value(0)
{}

LED::LED(int pin)
    : m_Pin(pin),
      m_Value(0)
{
    SetPin(pin);
}

void LED::SetValue(int value)
{
    value %= 256;
    value = value >= 0 ? value : value + 256;
    m_Value = value;
    if (m_Pin >= 0)
        analogWrite(m_Pin, value);
}

void LED::SetPin(int pin)
{
    m_Pin = pin;
    if (m_Pin >= 0)
        pinMode(pin, OUTPUT);
}

}