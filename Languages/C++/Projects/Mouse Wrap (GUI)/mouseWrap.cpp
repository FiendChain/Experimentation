#define _BSD_SOURCE
#define __USE_XOPEN

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
extern "C" {
    #include <xdo.h>
}

// consts
const int WIDTH = 1920;
const int HEIGHT = 1080;
const int PAD = 5;
const int FPS = 30;
const float dt = 1/(float)FPS;

// timer
struct Timer {
    float delay = 0;
    float cooldown = 0.1f;
};

// func prototype
void getInput(sf::RenderWindow& app, bool& isWrap, sf::Color& color, struct Timer& timer);
void wrapMouse(xdo_t *handler);
void toggleWrap(bool& isWrap, sf::Color& color, struct Timer& timer);

int main(int argc, char *argv[])
{
    // open sf window
    sf::RenderWindow app(sf::VideoMode(WIDTH/5.0f, HEIGHT/5.0f), "Mouse Wrap");
    app.setFramerateLimit(FPS);
    // get xdo 
    xdo_t *handler = xdo_new(NULL);
    // toggle wrap
    bool isWrap = true;
    sf::Color color = sf::Color::Green;
    // cooldown for inputs
    struct Timer timer;
    while(app.isOpen())
    {   
        // get input
        getInput(app, isWrap, color, timer);
        //render window
        app.clear(color);
        app.display();
        // get mouse position
        if(isWrap) wrapMouse(handler);
    }
    xdo_free(handler);

    return 0;
}

// get input
void getInput(sf::RenderWindow& app, bool& isWrap, sf::Color& color, struct Timer& timer)
{
    sf::Event event;
    while(app.pollEvent(event))
    {
        switch(event.type) 
        {
            case sf::Event::Closed:
                app.close();
            case sf::Event::KeyPressed:
                // keyboard press
                if(timer.delay > 0) break;
                switch(event.key.code)
                {
                    case sf::Keyboard::Space:
                        toggleWrap(isWrap, color, timer);
                }
            case sf::Event::MouseButtonPressed:
                if(timer.delay > 0) break;
                switch(event.mouseButton.button)
                {
                    case sf::Mouse::Left:
                        toggleWrap(isWrap, color, timer);
                }
        }
    }
    if(timer.delay > 0)
    {
        timer.delay -= dt;
    }
}

// wrap mouse
void wrapMouse(xdo_t *handler)
{
    static int x, y, screen;
    xdo_get_mouse_location(handler, &x, &y, &screen);
    // left and right wrap
    if(x <= 0)
    {
        xdo_send_keysequence_window_down(handler, screen, "ctrl", 0);
        xdo_move_mouse(handler, WIDTH-PAD, y, screen);
        xdo_send_keysequence_window_up(handler, screen, "ctrl", 0);
    }
    else if(x >= WIDTH-1)
    {
        xdo_send_keysequence_window_down(handler, screen, "ctrl", 0);
        xdo_move_mouse(handler, PAD, y, screen);
        xdo_send_keysequence_window_up(handler, screen, "ctrl", 0);
    }
    // top and bottom wrap
    if(y <= 0)
    {
        xdo_send_keysequence_window_down(handler, screen, "ctrl", 0);
        xdo_move_mouse(handler, x, HEIGHT-PAD, screen);
        xdo_send_keysequence_window_up(handler, screen, "ctrl", 0);
    }
    else if(y >= HEIGHT-1)
    {
        xdo_send_keysequence_window_down(handler, screen, "ctrl", 0);
        xdo_move_mouse(handler, x, PAD, screen);
        xdo_send_keysequence_window_up(handler, screen, "ctrl", 0);
    }
}

// toggle wrap
void toggleWrap(bool& isWrap, sf::Color& color, struct Timer& timer)
{
    isWrap = !isWrap;
    if(isWrap) color = sf::Color::Green;
    else       color = sf::Color::Red;
    timer.delay = timer.cooldown;
}