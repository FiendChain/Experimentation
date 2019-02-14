#pragma once

#include "../ILEDController.hpp"

class Oscillator: public ILEDController
{
    private:
        int mValue;
        int mMin, mMax;
        int mSpeed;
        bool mIsIncreasing;
    public:
        Oscillator(int min=0, int max=255, int speed=1);
        void SetSpeed(int speed);
        void SetRange(int min, int max);
        void Update();
        inline int GetMin() const { return mMin; }
        inline int GetMax() const { return mMax; }
        inline int GetSpeed() const { return mSpeed; }
        inline int GetValue() const { return mValue; }
};