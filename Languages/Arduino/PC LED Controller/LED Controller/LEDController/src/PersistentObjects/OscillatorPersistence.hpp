#pragma once

#include "../IPersistentObject.hpp"
#include "../LEDControllers/Oscillator.hpp"


class OscillatorPersistence: public IPersistentObject
{
    private:
        Oscillator *mOscillator;
        const int mAddr;
        struct DataFields {
            int min, max, speed;
        };
    public:
        OscillatorPersistence(Oscillator *oscillator, int addr);
        void Load();
        void Save();
        int GetSize() const { return sizeof(DataFields); } 
        int GetAddrStart() const { return mAddr; }
        int GetAddrEnd() const { return mAddr+GetSize(); }
};
