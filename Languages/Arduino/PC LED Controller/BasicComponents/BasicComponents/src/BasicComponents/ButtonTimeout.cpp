#include "ButtonTimeout.hpp"

namespace bc
{

ButtonTimeout::ButtonTimeout(int pin, unsigned duration)
    : Button(pin),
      m_Timer(duration),
      m_State(false)
{
}

void ButtonTimeout::SetDuration(unsigned duration)
{
    m_Timer.SetDuration(duration);
}

bool ButtonTimeout::GetState()
{
    bool currState = Button::GetState();
    if (currState)
    {
        m_Timer.Reset();
        m_State = currState;
    }
    else if (!currState && m_Timer.Check())
    {
        m_State = currState;
    }
    return m_State;
}

}