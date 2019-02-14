#include "Oscillator.hpp"

Oscillator::Oscillator(int min, int max, int speed)
    : mValue(min),
      mMin(min), mMax(max),
      mSpeed(speed),
      mIsIncreasing(true)
{
    SetSpeed(speed);
}   

void Oscillator::SetSpeed(int speed)
{
    speed %= mMax;
    speed = speed > 0 ? speed : speed + mMax;
    mSpeed = speed;
}

void Oscillator::Update()
{
    if (mIsIncreasing)
    {
        mValue += mSpeed;
        if (mValue > mMax)
        {
            mIsIncreasing = false;
            mValue = mMax;
        }
    }
    else
    {
        mValue -= mSpeed;
        if (mValue < mMin)
        {
            mIsIncreasing = true;
            mValue = mMin;
        }
    }
}

void Oscillator::SetRange(int min, int max)
{
    if (min < max) {
        mMin = min;
        mMax = max;
    }
}