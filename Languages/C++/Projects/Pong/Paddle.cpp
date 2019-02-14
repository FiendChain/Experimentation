#include "pong.hpp"
#include <SFML/Graphics.hpp>

using sf::Color;
using sf::RectangleShape;
using sf::RenderWindow;
using sf::Vector2f;
using pong::Paddle;

const int Paddle::up = 0;
const int Paddle::down = 1;

Paddle::Paddle(float widthSet, float heightSet, float speedSet, Vector resSet) {
    width = widthSet;
    height = heightSet;
    speed = speedSet; 
    res = resSet;
    dt = 1;
}

void Paddle::draw(RenderWindow &app) {
    static RectangleShape shape(Vector2f(width, height));
    shape.setPosition(pos.x-width/2.0, pos.y-height/2.0);
    shape.setFillColor(Color::White);
    app.draw(shape);
}

void Paddle::bound() {
    if(pos.y - height/2.0 < 0) {
        pos.y = height/2.0;
        vel.y = 0;
    } else if(pos.y + height/2.0 > res.y) {
        pos.y = res.y - height/2.0;
        vel.y = 0;
    } 
}

void Paddle::update() {
    pos += vel*dt;
    bound();
}

// Control the paddle
void Paddle::move(int dir) {
    if(dir == down) {
        vel.y = speed;
    } else if(dir == up) {
        vel.y = -speed;
    } else {
        vel.y = 0;
    }
}

void Paddle::stop() {
    vel.y = 0;
}

// Check if coordinate is inside the paddle
bool Paddle::checkYInside(float y) {
    return (pos.y - height/2.0 < y &&
            pos.y + height/2.0 > y);
}

bool Paddle::checkXInside(float x) {
    return (pos.x - width/2.0 < x &&
            pos.x + width/2.0 > x);
}