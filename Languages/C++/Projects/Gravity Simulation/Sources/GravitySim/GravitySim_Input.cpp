#include "GravitySim.hpp"
#include <SFML/Graphics.hpp>

// poll events
void GravitySim::getInput()
{
    sf::Event event;
    while(app.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                app.close();
                break;
        }
    }
    // keyboard inputs
    static float dist = 20;
    if(inputTimer.delay <= 0)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            translate(0, dist);
            inputTimer.delay = inputTimer.cooldown;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            translate(0, -dist);
            inputTimer.delay = inputTimer.cooldown;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            translate(dist, 0);
            inputTimer.delay = inputTimer.cooldown;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            translate(-dist, 0);
            inputTimer.delay = inputTimer.cooldown;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::LBracket))
        {
            if(tickrate > 0) tickrate -= 1;
            dt = tickrate/(float)fps;
            inputTimer.delay = inputTimer.cooldown;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::RBracket))
        {
            tickrate += 1;
            dt = tickrate/(float)fps;
            inputTimer.delay = inputTimer.cooldown;
        }
    }
    else
    {
        inputTimer.delay -= 1/(float)fps;
    }
}