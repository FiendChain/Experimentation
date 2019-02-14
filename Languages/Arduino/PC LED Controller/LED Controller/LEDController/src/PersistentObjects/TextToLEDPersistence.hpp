#pragma once
#include "../IPersistentObject.hpp"
#include "../LEDControllers/TextToLED/TextToLED.hpp"

class TextToLEDPersistence: public IPersistentObject
{
    private:
        TextToLED *mController;
        int mAddr;
        struct DataFields {
            int tickLength;
        };
    public:
        TextToLEDPersistence(TextToLED *controller, int addr);
        void Load();
        void Save();
        int GetSize() const { return sizeof(DataFields); }
        int GetAddrStart() const { return mAddr; }
        int GetAddrEnd() const { return mAddr+GetSize(); }
};