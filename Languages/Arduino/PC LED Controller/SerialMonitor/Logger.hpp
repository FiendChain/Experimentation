#pragma once
#include "IRunnable.hpp"
#include <string>
#include <vector>
#include <array>
#include <SFML/Graphics.hpp>

class Logger: public IRunnable
{
    private:
        std::vector<std::vector<char>> mConsole;
        int mCurrLine;
    public:
        Logger();
        void Clear();
        void Render() {}
        void OnImGui();
        void PollEvent(const sf::Event& event) {}
        void Update(float deltatime) {}
        void WriteLine(const std::vector<char>& line);
};