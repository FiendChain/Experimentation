#include "Body.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

// constructor
Body::Body(float mass, float radius)
:   fixed(false),
    mass(mass),
    vel(0, 0),
    acc(0, 0)
{
    setRadius(radius);
    setOrigin(radius, radius);
    setPosition(0, 0);
    setFillColor(sf::Color::White);
}

// get mass
float Body::getMass()
{
    return mass;
}

// apply physics
void Body::applyForce(sf::Vector2f force)
{
    acc += force / mass;
}

// setters
void Body::setVelocity(float x, float y)
{
    vel.x = x;
    vel.y = y;
}

void Body::setVelocity(sf::Vector2f vel)
{
    this->vel = vel;
}

// getters
sf::Vector2f Body::getVelocity()
{
    return vel;
}

sf::Vector2f Body::getAcceleration()
{
    return acc;
}

// update physics
void Body::update(float dt)
{
    if(!fixed)
    {
        vel += acc*dt;
        sf::Vector2f pos = getPosition();
        pos += vel*dt;
        setPosition(pos);
        acc *= 0.0f;
    }
}


