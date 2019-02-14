#include "pong.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>

using sf::Color;
using sf::RectangleShape;
using sf::RenderWindow;
using sf::Vector2f;

using sf::Text;
using sf::Font;

using sf::Sound;
using sf::SoundBuffer;

using std::to_string;

using pong::Ball;

Ball::Ball(float radiusSet, float speedSet, Vector resSet) {
    radius = radiusSet;
    speed = speedSet;
    res = resSet;
    dt = 1;
    angleDeflection = 75.0f * M_PI/180.0f;
    setupScore();
    setupSound();
}

void Ball::update() {
    pos += vel*dt;
    bound();
}

void Ball::bound() {
    // Bounce if it hit top or bottom edge
    if(pos.y - radius < 0 && vel.y < 0) {
        vel.y *= -1;
        playBounceSound();
    } else if(pos.y + radius > res.y && vel.y > 0) {
        vel.y *= -1;
        playBounceSound();
    }
    // Reset if edges are reached
    if(pos.x - radius < 0) {            // Left loses
        score.right += 1;
        reset();
        vel.set(speed, speed);
    } else if(pos.x + radius > res.x) { // Right loses
        score.left += 1;
        reset();
        vel.set(-speed, speed);
    }
}

void Ball::bounce(Paddle &p) {
    if (   (p.checkYInside(pos.y+radius) || p.checkYInside(pos.y-radius))
        && (p.checkXInside(pos.x+radius) || p.checkXInside(pos.x-radius)))
    {
        if ((pos.x-p.pos.x)*vel.x < 0) {
            float posYDiff = pos.y-p.pos.y;
            float normalisedPosYDiff = (float)posYDiff/(float)p.height;
            float bounceAngle = normalisedPosYDiff * angleDeflection;
            vel.y = speed * sin(bounceAngle);
            vel.x = speed * cos(bounceAngle) * (vel.x < 0 ? 1:-1);
        }
    }
}


// void Ball::bounce(Paddle &p) {
//     if(p.checkYInside(pos.y + radius) || p.checkYInside(pos.y - radius)) {
//         // Right side
//         if(p.checkXInside(pos.x - radius) && vel.x < 0) {
//             vel.x *= -1;
//             vel.y += p.vel.y;
//             playBounceSound();
//         // Left side
//         } else if(p.checkXInside(pos.x + radius) && vel.x > 0) {
//             vel.x *= -1;
//             vel.y += p.vel.y;
//             playBounceSound();
//         }
//     }
// }

void Ball::draw(RenderWindow &app) {
    static RectangleShape shape(Vector2f(2*radius, 2*radius));
    shape.setPosition(pos.x-radius, pos.y-radius);
    shape.setFillColor(Color::White);
    app.draw(shape);
}

void Ball::showScore(RenderWindow &app) {
    score.leftText.setString(to_string(score.left));
    score.rightText.setString(to_string(score.right));
    app.draw(score.leftText);
    app.draw(score.rightText);
}

void Ball::setupScore() {
    score.font.loadFromFile("./Arial.ttf");
    score.left = score.right = 0;
    // Left text
    score.leftText.setString(to_string(score.left));
    score.leftText.setFont(score.font);
    score.leftText.setColor(Color::White);
    score.leftText.setStyle(Text::Bold);
    score.leftText.setPosition(sf::Vector2f(0.75f*res.x/4.0f, res.y/10.0f));
    score.leftText.setCharacterSize(res.y/10.0f);
    // Right text
    score.rightText.setString(to_string(score.right));
    score.rightText.setFont(score.font);
    score.rightText.setColor(Color::White);
    score.rightText.setStyle(Text::Bold);
    score.rightText.setPosition(sf::Vector2f(3*res.x/4.0f, res.y/10.0f));
    score.rightText.setCharacterSize(res.y/10.0f);
}

void Ball::playBounceSound() {
    bounceSound.sound.play();
} 

void Ball::setupSound() {
    bounceSound.buffer.loadFromFile("pongSound.ogg"); 
    bounceSound.sound.setBuffer(bounceSound.buffer);
}

void Ball::reset() {
    pos.x = res.x/2.0;
    pos.y = res.y/2.0;
}