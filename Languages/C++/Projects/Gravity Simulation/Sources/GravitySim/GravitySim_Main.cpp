#include "GravitySim.hpp" 
#include <SFML/Graphics.hpp>

// constructor
GravitySim::GravitySim(int width, int height, int fps, float tickrate)
:   app(sf::VideoMode(width, height), "Gravity Simulation"),
    G(1000.0f),
    fps(fps),
    tickrate(tickrate),
    dt(tickrate/(float)fps)
{
    app.setFramerateLimit(fps);
    inputTimer.delay = 0;
    inputTimer.cooldown = 0.1f;
    initText();
}

// destructor
GravitySim::~GravitySim()
{

}

// exec gravity simulation
bool GravitySim::run() 
{
    getInput();
    updateBodies();
    updateText();
    draw();
    return app.isOpen();
}