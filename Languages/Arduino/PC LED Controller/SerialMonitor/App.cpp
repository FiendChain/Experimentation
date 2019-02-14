#include "App.hpp"
#include <string>
#include <imgui/imgui.h>
#include <imgui-sfml/imgui-SFML.h>
#include <SFML/Graphics.hpp>

App::App(unsigned width, unsigned height, const std::string& title)
    : mWindow(sf::VideoMode(width, height), title),
      mWidth(width), mHeight(height),
      mRunnable(nullptr)
{ 
    mWindow.setFramerateLimit(60);
    ImGui::SFML::Init(mWindow);
} 

void App::Run()
{
    while (mWindow.isOpen())
    {
        PollEvents();
        Update();
        Render();
    }
}

void App::PollEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        ImGui::SFML::ProcessEvent(event);
        if (mRunnable) mRunnable->PollEvent(event);
        if (event.type == sf::Event::Closed)
        {
            mWindow.close();
        }
    }
}

void App::Render()
{
    mWindow.clear(sf::Color::Black);
    if (mRunnable) mRunnable->OnImGui();
    ImGui::SFML::Render(mWindow);
    if (mRunnable) mRunnable->Render();
    mWindow.display();
}

void App::Update()
{
    sf::Time frameTime = mClock.restart();
    ImGui::SFML::Update(mWindow, frameTime);
    if (mRunnable) mRunnable->Update(frameTime.asMilliseconds());
}

