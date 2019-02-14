#include "App.hpp"
#include <stdio.h>

void App::init() {
    // rng
    initRngEngine();
    // init graphics
    initLinesBuffer();
    initBalls();
    initConnector();
    initFont();
    // init hud elements
    initOverlay();
}

void App::initLinesBuffer() {
    if (!linesBuffer.create(resolution.x, resolution.y)) {
        throw "Couldn't create double buffer!\n";
    }
    linesBuffer.clear(sf::Color::Transparent);
    linesBuffer.display();
}

void App::initBalls() {
    // randomisers
    std::uniform_real_distribution<float> pos_x(0, resolution.x),
                                          pos_y(0, resolution.y),
                                          vel_x(50, 100),
                                          vel_y(50, 100);
    // set properties
    for (int i = 0; i < totalBalls; i++) {
        Ball ball(10);
        ball.setFillColor(sf::Color::White);
        ball.setPosition(pos_x(rng_engine), pos_y(rng_engine));
        ball.setVelocity(vel_x(rng_engine), vel_y(rng_engine));
        balls.push_back(ball);
    }
}

void App::initConnector() {
    updateConnector();
}

void App::initFont() {
    if (!font.loadFromFile("resources/Arial.ttf")) {
        perror("Couldn't load font");
        exit(1);
    }
}

void App::initOverlay() {
    overlay.setColor(sf::Color::White);
    overlay.setPosition(20, 20);
    overlay.setCharacterSize(20);
    overlay.setFont(font);
}