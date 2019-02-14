#pragma once

#include "ITextToLEDEncoder.hpp"

class TapCodeEncoder: public ITextToLEDEncoder
{
    private:
        enum EncoderState { IDLE, TAP, WAIT_TAP, WAIT_CODE };
        int (*mTable)[26][2];
        char *mText;
        int mTextLength;
        int mCurrentTextIndex;
        int mCurrentTapIndex;
        int mCurrentCountdown; // To count each tap
        EncoderState mCurrentState;
    public:
        TapCodeEncoder(int (*table)[26][2]);
        void SetString(char *text);
        void Reset();
        TextToLEDState GetState();
    private:
        TextToLEDState GetNormalisedState();
        bool Next();
        int GetTapIndex(char c);
};