#pragma once

#include "../ILEDController.hpp"

class SteadyState: public ILEDController
{
    private:
        int mValue;
    public:
        SteadyState(int value=0); 
        void Update();
        int GetValue() const;
        void SetValue(int value); 
};