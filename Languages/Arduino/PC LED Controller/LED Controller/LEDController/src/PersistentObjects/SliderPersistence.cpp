#include "SliderPersistence.hpp"
#include <EEPROM.h>

SliderPersistence::SliderPersistence(Slider *slider, int addr)
    : mSlider(slider),
      mAddr(addr)
{

}

void SliderPersistence::Load() 
{
    DataFields data = {0};
    EEPROM.get(mAddr, data);
    if (!mSlider->SetValue(data.value))
    {
        mSlider->SetValue(0);
        Save();
    }
}

void SliderPersistence::Save()
{
    DataFields data = {
        mSlider->GetValue(),
    };
    EEPROM.put(mAddr, data);
}