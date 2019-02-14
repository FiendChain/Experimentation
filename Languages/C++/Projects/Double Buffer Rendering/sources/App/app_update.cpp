#include "App.hpp"
#include "../Ball/BallPhysics.hpp"
#include <stdio.h>

void App::update() {
    sf::Time currentTime = clock.getElapsedTime();
    sf::Time lastUpdate = currentTime;
    sf::Time lastLinesBufferUpdate = currentTime;
    // update loop
    while (window.isOpen()) {
        currentTime = clock.getElapsedTime();
        if ((currentTime - lastUpdate).asSeconds() > dt) {
            lastUpdate = currentTime;
            updatePhysics();
            updateConnector();
            if (showOverlay) {
                updateOverlay();
            }
        }
        if ((currentTime - lastLinesBufferUpdate).asSeconds() > delayMultiplier*dt) {
            lastLinesBufferUpdate = currentTime;
            updateLinesBuffer();
        }
    }
}

void App::updatePhysics() {
    apply_surface_gravity(balls, 0, balls.size());
    bounce_inside_box(balls, resolution, 0, balls.size());
    update_balls(balls, 0, balls.size(), dt);
    rainbow.update(); 
}

void App::updateLinesBuffer() {
    linesBuffer.draw(connector);
    linesBuffer.updateFade();
    linesBuffer.display();
}

void App::updateConnector() {
    for (int i = 0; i < totalBalls; i++) {
        Ball &ball = balls.at(i);
        connector[i].position = ball.getPosition();
        connector[i].color = rainbow;
    }
    connector[totalBalls].position = balls.at(0).getPosition();
    connector[totalBalls].color = rainbow;
}

void App::updateOverlay() {
    char buffer[200] = {0};
    snprintf(buffer, 200, "dt: %.3lf\nrainbow alpha: %d\ndelay multiplier: %d", dt, rainbow.a, delayMultiplier);
    overlay.setString(buffer);
}