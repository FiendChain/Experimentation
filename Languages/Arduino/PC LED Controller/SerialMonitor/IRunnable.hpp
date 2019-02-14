#pragma once
#include <SFML/Graphics.hpp>

class IRunnable
{
    public:
        virtual void Render() = 0;
        virtual void OnImGui() = 0;
        virtual void Update(float deltatime) = 0;
        virtual void PollEvent(const sf::Event& event) = 0;
};