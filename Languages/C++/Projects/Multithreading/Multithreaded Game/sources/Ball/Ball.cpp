#include "Ball.hpp"
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

Ball::Ball(float radius)
    :velocity(0, 0),
     acceleration(0, 0)
{
    setPosition(0, 0);
    setRadius(radius);
    setFillColor(sf::Color::White);
}

void Ball::update(float dt) {
    velocity += acceleration*dt;
    setPosition(getPosition() + velocity*dt);
    acceleration.x = acceleration.y = 0;
}

void Ball::setRadius(float radius) {
    if (radius <= 0) {
        throw "Cannot have negative radius for Ball object";
    }
    CircleShape::setRadius(radius);
    setOrigin(radius, radius);
    float volume = 4/3.0 * M_PI * pow(radius, 3);  // volume = 4/3 * pi * r^3
    this->mass = volume * density; // m = pV 
}

void Ball::setVelocity(float x, float y) {
    velocity.x = x;
    velocity.y = y;
}

sf::Vector2f Ball::getVelocity() {
    return velocity;
}

float Ball::getMass() {
    return mass;
}

void Ball::applyForce(float x, float y) {
    // f = m*a
    // a = f/m
    applyAcceleration(x/mass, y/mass);
}

void Ball::applyAcceleration(float x, float y) {
    acceleration.x += x;
    acceleration.y += y;
}