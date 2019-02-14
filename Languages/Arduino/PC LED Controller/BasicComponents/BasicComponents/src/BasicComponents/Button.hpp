#pragma once

namespace bc // basic components
{

class Button
{
    private:
        int m_Pin;
    public:
        Button();
        Button(int pin);
        void SetPin(int pin);
        virtual bool GetState();
};

}