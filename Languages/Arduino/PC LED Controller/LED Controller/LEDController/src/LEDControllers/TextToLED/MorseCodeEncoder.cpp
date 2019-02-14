#include "MorseCodeEncoder.hpp"
#include <string.h>

MorseCodeEncoder::MorseCodeEncoder(const char **table)
    : mTable(table),
      mText(nullptr),
      mTextLength(0),
      mCurrentLetterIndex(0),
      mCurrentMorseCodeIndex(0),
      mCurrentState(IDLE)
{

}

void MorseCodeEncoder::SetString(char *text)
{
    mText = text;
    mTextLength = strlen(text);
    mCurrentState = MORSE;
    mCurrentLetterIndex = 0;
    mCurrentMorseCodeIndex = 0;
}

TextToLEDState MorseCodeEncoder::GetState()
{
    TextToLEDState state = GetNormalisedState();
    state.value *= 255;
    return state;
}

TextToLEDState MorseCodeEncoder::GetNormalisedState()
{
    switch (mCurrentState)
    {
    case IDLE:
        return {0,-1};
    case MORSE:
        // end of morse code reached, set to idle
        if (mText == nullptr || mCurrentLetterIndex == mTextLength)
        {
            mCurrentState = IDLE;
            return {0,-1};
        }
        // get the led state, and predict type of wait
        switch (GetNextMorseCode())
        {
        case '.':
            return {1,1};
        case '-':
            return {1,3};
            break;
        case 0:
        default:
            return {0,-1};
        }
    case MORSE_WAIT:
        mCurrentState = MORSE;
        return {0,1};
    case LETTER_WAIT:
        mCurrentState = MORSE;
        return {0,3};
    case WORD_WAIT:
        mCurrentState = MORSE;
        return {0,7};
    }
}

void MorseCodeEncoder::Reset()
{
    mText = nullptr;
    mCurrentState = IDLE;
    mCurrentLetterIndex = 0;
    mCurrentMorseCodeIndex = 0;
}

int MorseCodeEncoder::GetMorseIndex(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return (c-'a');
    }
    else if (c >= 'A' && c <= 'Z')
    {
        return (c-'A');
    }
    else if (c >= '0' && c <= '9') 
    {
        return (c-'0') + 26;
    }
    return -1;
}

char MorseCodeEncoder::GetNextMorseCode()
{
    // get next morse code
    char morse = 0;
    const char *morseCode = nullptr;
    while (morse == 0 && mCurrentLetterIndex < mTextLength)
    {
        char currLetter = mText[mCurrentLetterIndex];
        int index = GetMorseIndex(currLetter);
        // if invalid character, move onto next character
        if (index == -1) {
            mCurrentLetterIndex++;
            mCurrentMorseCodeIndex = 0;
            continue;
        }
        morseCode = mTable[index];
        morse = morseCode[mCurrentMorseCodeIndex];
        // end of morse recieved, move onto next letter 
        if (morse == 0) {
            mCurrentLetterIndex++;
            mCurrentMorseCodeIndex = 0;
        }
    }
    // no valid morse code means finished string
    mCurrentState = IDLE;
    if (morse == 0) 
    {
        mCurrentState = IDLE;
    }
    // if next morse code is valid, then just have a morse wait
    else if (morseCode[++mCurrentMorseCodeIndex] != 0) 
    {
        mCurrentState = MORSE_WAIT;
    }
    // if current morse code is finished, get next valid letter
    else
    {
        mCurrentMorseCodeIndex = 0; // start on next letter
        mCurrentLetterIndex++;
        while (mCurrentLetterIndex < mTextLength)
        {
            char currLetter = mText[mCurrentLetterIndex];
            // next char is a space
            if (currLetter == ' ') 
            {
                mCurrentState = WORD_WAIT;
                break;
            }
            // next char is a letter
            else if (GetMorseIndex(currLetter) != -1)
            {
                mCurrentState = LETTER_WAIT;
                break;
            }
            mCurrentLetterIndex++;
        }
    }
    return morse;
}