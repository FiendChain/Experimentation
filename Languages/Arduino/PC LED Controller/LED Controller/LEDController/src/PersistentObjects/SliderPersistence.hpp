#pragma once

#include "../IPersistentObject.hpp"
#include "../LEDControllers/Slider.hpp"

class SliderPersistence: public IPersistentObject
{
    private:
        Slider *mSlider;
        int mAddr;
        struct DataFields {
            int value;
        };
    public:
        SliderPersistence(Slider *slider, int addr);
        void Load();
        void Save();
        int GetSize() const { return sizeof(DataFields); }
        int GetAddrStart() const { return mAddr; }
        int GetAddrEnd() const { return mAddr+GetSize(); }
};