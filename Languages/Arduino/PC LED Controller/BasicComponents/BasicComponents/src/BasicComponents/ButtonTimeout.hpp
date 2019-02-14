#pragma once

#include "Button.hpp"
#include "Timer.hpp"

namespace bc
{

class ButtonTimeout: public Button
{
    private:
        Timer m_Timer;
        bool m_State;
    public:
        ButtonTimeout(int pin=-1, unsigned duration=0);
        void SetDuration(unsigned duration);
        bool GetState() override;

};

}