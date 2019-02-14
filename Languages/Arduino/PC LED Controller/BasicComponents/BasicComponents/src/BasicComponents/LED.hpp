#pragma once

namespace bc
{

class LED
{
    private:
        int m_Pin;
        int m_Value;
    public:
        LED();
        LED(int pin);
        inline int GetValue() const { return m_Value; }
        void SetValue(int value);
        void SetPin(int pin);
};

}