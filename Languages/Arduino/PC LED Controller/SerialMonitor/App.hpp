#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "IRunnable.hpp"

class App
{
    private:
        sf::RenderWindow mWindow;
        sf::Clock mClock;
        IRunnable *mRunnable;
        const unsigned mWidth, mHeight;
    public:
        App(unsigned width, unsigned height, const std::string& title);
        void Run();
        void SetRunnable(IRunnable *runnable) { mRunnable = runnable; }
    private:
        void PollEvents();
        void Render();
        void Update();

};


