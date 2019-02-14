#include "TapCodeEncoder.hpp"
#include <string.h>

TapCodeEncoder::TapCodeEncoder(int (*table)[26][2])
    : mTable(table),
      mText(nullptr),
      mTextLength(0),
      mCurrentTextIndex(0),
      mCurrentTapIndex(0),
      mCurrentCountdown(0),
      mCurrentState(IDLE)
{

}

void TapCodeEncoder::SetString(char *text)
{
    mText = text;
    mTextLength = strlen(text);
    mCurrentTextIndex = 0;
    mCurrentTapIndex = 0;
    mCurrentCountdown = 0;
    // initiate the state machine
    Next();              // prime the state machine
    mCurrentState = TAP; // skip the WAIT_CODE at the begining
}

void TapCodeEncoder::Reset()
{
    mText = nullptr;
    mTextLength = 0;
    mCurrentState = IDLE;
    mCurrentTextIndex = 0;
    mCurrentTapIndex = 0;
    mCurrentCountdown = 0;
}

TextToLEDState TapCodeEncoder::GetState()
{
    TextToLEDState state = GetNormalisedState();
    state.value *= 255;
    return state;
}

TextToLEDState TapCodeEncoder::GetNormalisedState()
{
    switch (mCurrentState)
    {
    case IDLE:
        return {0,-1};
    case TAP:
        if (Next()) 
        {
            return {1, 1};
        }
        return {0, 0};
    case WAIT_TAP:
        mCurrentState = TAP;
        return {0, 1};
    case WAIT_CODE:
        mCurrentState = TAP;
        return {0, 3};
    }
    return {0,-1};
}

int TapCodeEncoder::GetTapIndex(char c)
{
    if (c >= 'a' && c <= 'z') 
    {
        return (c-'a');
    }
    else if (c >= 'A' && c <= 'Z')
    {
        return (c-'A');
    }
    return -1;
}

// true to blink, false to not blink
bool TapCodeEncoder::Next()
{
    // perform the countdown
    if (mCurrentCountdown > 0)
    {
        mCurrentCountdown--;
        mCurrentState = WAIT_TAP;
        return true;
    }
    // if reached end of current tap code, find next letter
    if (mCurrentTapIndex >= 2)
    {
        mCurrentTextIndex++;
        mCurrentTapIndex = 0;
    }
    while (mCurrentTextIndex < mTextLength)
    {
        char c = mText[mCurrentTextIndex];
        int tapTableIndex = GetTapIndex(c);
        // if invalid character, find next valid character
        if (tapTableIndex == -1)
        {
            mCurrentTextIndex++;
            mCurrentTapIndex = 0;
            continue;
        }
        // get the tap code for the letter
        mCurrentCountdown = (*mTable)[tapTableIndex][mCurrentTapIndex++]; 
        mCurrentState = WAIT_CODE;
        return false;
    }
    mCurrentState = IDLE;
    return false;
}