#include "GravitySim.hpp" 
#include <SFML/Graphics.hpp>
#include <math.h>

// add a body
void GravitySim::addBody(Body b)
{
    bodies.push_back(b);
}

// get gravity force vector
// F = GMm/r^2
// dir = a to b
sf::Vector2f GravitySim::gravityEquation(Body& a, Body& b)
{  
    sf::Vector2f dir = b.getPosition()-a.getPosition(); // dir = vector of displacement
    float rSquared = dir.x*dir.x + dir.y*dir.y;
    if(rSquared < 100) rSquared = 100;
    float F = G * a.getMass() * b.getMass() / rSquared; // F = GMm/r^2
    dir /= (float)pow(rSquared, 0.5f);                  // remove magnitude component of direction to get unit vector
    return F * dir;                                     // apply unit vector to magnitude to get force vector
}  

// update all bodies with gravity
void GravitySim::updateBodies()
{
    for(auto& a: bodies)
    {
        for(auto& b: bodies)
        {
            if(&a != &b)
            {
                sf::Vector2f force = gravityEquation(a, b);
                a.applyForce(force);
                a.update(dt); 
            }
        }
    }
}

// return true if bodies collide
bool collideBodies(Body& a, Body& b)
{
    sf::Vector2f dir = b.getPosition()-a.getPosition();
    float minRadius = a.getRadius()+b.getRadius();
    if(minRadius*minRadius < dir.x*dir.x + dir.y*dir.y)
    {
        return true;
    }
    else
    {
        return false;
    }
}


// get centre of mass
sf::CircleShape GravitySim::getCOM()
{
    float radius = 5;
    sf::CircleShape COM(radius);
    sf::Vector2f sum(0, 0);
    float totalMass = 0;
    for(auto&b: bodies)
    {
        sum += b.getPosition() * b.getMass();
        totalMass += b.getMass();
    }
    sum /= totalMass;
    COM.setPosition(sum);
    COM.setOrigin(radius, radius);
    COM.setFillColor(sf::Color::Red);
    return COM;
}

