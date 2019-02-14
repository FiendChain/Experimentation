#include "Timer.hpp"
#include <Arduino.h>

namespace bc
{

Timer::Timer(unsigned duration)
    : m_Duration(duration),
      m_LastUpdate(millis())
{

}

bool Timer::Check()
{
    if (millis()-m_LastUpdate >= m_Duration)
    {
        m_LastUpdate = millis();
        return true;
    }
    return false;
}

void Timer::Reset()
{
    m_LastUpdate = millis();
}

}