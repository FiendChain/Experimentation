#pragma once

struct TextToLEDState {
    int value;
    int totalTicks;
};

class ITextToLEDEncoder
{
    public:
        virtual void SetString(char *text) = 0;
        virtual void Reset() = 0;
        virtual TextToLEDState GetState() = 0;
};