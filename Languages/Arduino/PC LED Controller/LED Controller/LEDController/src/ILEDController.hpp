#pragma once

class ILEDController
{
    public:
        virtual void Update() = 0;
        virtual int GetValue() const = 0;
};
