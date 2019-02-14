#include "SteadyState.hpp"

SteadyState::SteadyState(int value)
    : mValue(value)
{

}

void SteadyState::SetValue(int value)
{
    mValue = value;
}

int SteadyState::GetValue() const 
{
    return mValue;
}

void SteadyState::Update()
{

}