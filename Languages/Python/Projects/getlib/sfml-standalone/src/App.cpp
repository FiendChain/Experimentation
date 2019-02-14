#include "App.hpp"
#include <SFML/Graphics.hpp>
#include <memory>
#include <random>
#include <time.h>
#include <functional>

#include <imgui/imgui.h>
#include <imgui-sfml/imgui-SFML.h>

App::App(unsigned int width, unsigned int height, unsigned int fps)
    : m_Width(width), m_Height(height), m_Fps(fps), 
      m_Window(sf::VideoMode(width, height), "MY_SFML_PROJECT"),
      m_RngEngine(time(NULL))
{
    m_Window.setFramerateLimit(m_Fps);
    ImGui::SFML::Init(m_Window);
}

App::~App()
{

}

void App::Run()
{
    sf::Thread updateThread(std::bind(&Update, this));
    updateThread.launch();
	
	sf::Time lastUpdate = m_Clock.getElapsedTime();
    static int frameTime = 1000/(float)m_Fps;
    while (m_Window.isOpen())
    {
        if ((m_Clock.getElapsedTime()-lastUpdate).asMilliseconds() > frameTime)
        {
            lastUpdate = m_Clock.getElapsedTime();
			m_Mutex.lock();
            Render();
			PollEvents();
			m_Mutex.unlock();
        }
    }
}

void App::PollEvents()
{
    sf::Event event;
    while (m_Window.pollEvent(event))
    {
        ImGui::SFML::ProcessEvent(event);
        if (event.type == sf::Event::Closed)
        {
            m_Window.close();
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {

            }
        }
    }
}

void App::Render()
{
    // window
    m_Window.clear(sf::Color::White);
    sf::RectangleShape testShape(sf::Vector2f(100, 100));
    testShape.setPosition(0, 0);
    testShape.setFillColor(sf::Color::Black);
    m_Window.draw(testShape);
    RenderImGui();
    ImGui::SFML::Render(m_Window);
    m_Window.display();
}

void App::RenderImGui()
{
    static sf::Clock imguiClock;
    ImGui::SFML::Update(m_Window, imguiClock.restart());
    ImGui::Begin("Info");
    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    ImGui::End();
}

void App::Update()
{
    sf::Time lastUpdate = m_Clock.getElapsedTime();
    static int updateTime = 1000/(float)m_Fps;
    while (m_Window.isOpen())
    {
        if ((m_Clock.getElapsedTime()-lastUpdate).asMilliseconds() > updateTime)
        {
            lastUpdate = m_Clock.getElapsedTime();
            m_Mutex.lock();
			m_Mutex.unlock();
        }
    }
}