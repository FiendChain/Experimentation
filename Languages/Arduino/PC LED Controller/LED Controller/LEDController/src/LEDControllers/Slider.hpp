#pragma once

#include "../ILEDController.hpp"

class Slider: public ILEDController
{
    private:
        int mValue;
    public:
        Slider(int value=0);
        void Update() { }
        int GetValue() const { return mValue; }
        bool SetValue(int value);
};