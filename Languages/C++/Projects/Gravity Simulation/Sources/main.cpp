#include "GravitySim/GravitySim.hpp"
#include <SFML/Graphics.hpp>

int main(int argc, char *argv[])
{
    GravitySim g(1920, 1080, 144, 25);
    // make planet
    Body planet(100, 20);
    planet.setPosition(1000, 500);
    planet.setVelocity(0, 0);
    //planet.fixed = true;
    // make moon
    Body moon(10, 5);
    moon.setPosition(700, 500);
    moon.setVelocity(0, 15);
    // make moon 2
    Body mun(10, 5);
    mun.setPosition(1300, 500);
    mun.setVelocity(0, -15);
    // add bodies
    g.addBody(planet);
    g.addBody(moon);
    g.addBody(mun);
    while(g.run());

    return 0;
}