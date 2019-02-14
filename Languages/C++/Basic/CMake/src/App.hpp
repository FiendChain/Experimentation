#pragma once
#include "Vector.hpp"

class App
{
    public:
        unsigned int mWidth, mHeight;
        unsigned int mFps;
    public:
        App() = default;
        App(unsigned int width, unsigned int height, unsigned int fps);
        inline auto GetResolution() const { return Vector3<unsigned int>(mWidth, mHeight, 0); }
};