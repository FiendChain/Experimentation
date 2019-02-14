#pragma once
#include "ITextToLEDEncoder.hpp"
// table layout
// 0-25: A-Z
// 26-35: 0-9

class MorseCodeEncoder: public ITextToLEDEncoder
{
    private:
        enum EncoderState { IDLE, MORSE, MORSE_WAIT, LETTER_WAIT, WORD_WAIT };
        const char **mTable;
        char *mText;
        EncoderState mCurrentState;
        int mTextLength;
        int mCurrentLetterIndex;     // keep track of indexes
        int mCurrentMorseCodeIndex;
    public:
        MorseCodeEncoder(const char **table);
        void SetString(char *text);
        TextToLEDState GetState();
        void Reset();
    private:
        TextToLEDState GetNormalisedState();
        int GetMorseIndex(char c);
        char GetNextMorseCode();
};