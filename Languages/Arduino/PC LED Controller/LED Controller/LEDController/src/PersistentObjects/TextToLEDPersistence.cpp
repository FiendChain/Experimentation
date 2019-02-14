#include "TextToLEDPersistence.hpp"
#include <EEPROM.h>

TextToLEDPersistence::TextToLEDPersistence(TextToLED *controller, int addr)
    : mController(controller),
      mAddr(addr)
{

}

void TextToLEDPersistence::Load()
{
    DataFields data = {25};
    EEPROM.get(mAddr, data);
    mController->SetTickLength(data.tickLength);
}

void TextToLEDPersistence::Save()
{
    DataFields data = {
        mController->GetTickLength(),
    };
    EEPROM.put(mAddr, data);
}
