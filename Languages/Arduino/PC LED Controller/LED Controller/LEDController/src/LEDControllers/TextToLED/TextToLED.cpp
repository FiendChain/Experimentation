#include "TextToLED.hpp"
#include <string.h>

TextToLED::TextToLED(ITextToLEDEncoder *encoder, int tickLength)
    : mEncoder(encoder),
      mTickLength(tickLength),
      mTotalTicks(0),
      mCurrentState{0, -1},
      mBuffer{0}
{

}

void TextToLED::SetString(char *text)
{
    strncpy(mBuffer, text, TEXT_TO_LED_BUFFER_SIZE);
    Start(); 
}

void TextToLED::SetTickLength(int tickLength)
{
    if (tickLength > 0)
    {
        mTickLength = tickLength; 
    }
}

void TextToLED::Update()
{
    // if not infinite time (-1) and reached tick goal
    if (mCurrentState.totalTicks != -1 )
    {
        mTotalTicks++; 
        if(mCurrentState.totalTicks * mTickLength <= mTotalTicks)
        {
            mTotalTicks = 0;
            mCurrentState = mEncoder->GetState();
        }
    } 
}

void TextToLED::Stop()
{
    mEncoder->Reset();
    mCurrentState = {0,-1};
}

void TextToLED::Start()
{
    mEncoder->SetString(mBuffer);
    mCurrentState = mEncoder->GetState();
}

int TextToLED::GetValue() const
{
    return mCurrentState.value;
}
