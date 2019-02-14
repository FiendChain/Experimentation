#include "OscillatorPersistence.hpp"
#include <EEPROM.h>

OscillatorPersistence::OscillatorPersistence(Oscillator *oscillator, int addr) 
    : mOscillator(oscillator),
      mAddr(addr)
{

}

void OscillatorPersistence::Load()
{
    DataFields data = {0};
    EEPROM.get(mAddr, data);
    mOscillator->SetRange(data.min, data.max);
    mOscillator->SetSpeed(data.speed);
}

void OscillatorPersistence::Save()
{
    DataFields data = {
        mOscillator->GetMin(),
        mOscillator->GetMax(),
        mOscillator->GetSpeed(),
    };
    EEPROM.put(mAddr, data);
}