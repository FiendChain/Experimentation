#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <random>
#include <vector>

class App
{
    private:
        sf::RenderWindow m_Window;
        const unsigned int m_Width, m_Height, m_Fps;
        sf::Clock m_Clock;
        std::mt19937 m_RngEngine;
		sf::Mutex m_Mutex;
    public:
        App(unsigned int width, unsigned int height, unsigned int fps);
        ~App();
        void Run();
    private:
        void PollEvents();
        void Render();
        void RenderImGui();
        void Update();
};