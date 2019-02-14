#pragma once

#include "../../ILEDController.hpp"
#include "ITextToLEDEncoder.hpp"

#define TEXT_TO_LED_BUFFER_SIZE 100

class TextToLED: public ILEDController
{
    private:
        int mTickLength;
        int mTotalTicks;
        TextToLEDState mCurrentState;
        ITextToLEDEncoder *mEncoder;
        char mBuffer[TEXT_TO_LED_BUFFER_SIZE];
    public:
        TextToLED(ITextToLEDEncoder *encoder, int tickLength=25);
        void SetString(char *text);
        void SetTickLength(int tickLength);
        int GetTickLength() const { return mTickLength; }
        void Stop();
        void Start();
        void Update();
        int GetValue() const;
}; 