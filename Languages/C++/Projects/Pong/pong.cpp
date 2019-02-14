#include "pong.hpp"
#include "Config.hpp"
#include <SFML/Graphics.hpp>
// Scan arguments
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using std::string;
using namespace sf;
using namespace pong;

int main(int argc, char *argv[]) {
    Config c;
    c.getConfig(argc, argv);
    // Game settings
    string windowTitle = "Pong Game";
    float dt = c.tickrate / (float)c.fps;
    // Left paddle
    Paddle leftPaddle(c.paddleWidth, c.paddleHeight, c.paddleSpeed, c.res);
    leftPaddle.dt = dt;
    leftPaddle.pos.set(leftPaddle.width, c.res.y/2.0);
    // Right paddle
    Paddle rightPaddle(c.paddleWidth, c.paddleHeight, c.paddleSpeed, c.res);
    rightPaddle.dt = dt;
    rightPaddle.pos.set(c.res.x-rightPaddle.width, c.res.y/2.0);
    // Ball
    Ball ball(c.ballRadius, c.ballSpeed, c.res);
    ball.dt = dt; 
    ball.pos.set(c.res.x/2.0, c.res.y/2.0);
    ball.vel.set(c.ballSpeed, c.ballSpeed);
    // Create bots
    PaddleBot leftPaddleBot(ball, leftPaddle, c.botSkill);
    PaddleBot rightPaddleBot(ball, rightPaddle, c.botSkill);
    // Draw separator
    RectangleShape sep(Vector2f(c.res.x/200.0f, c.res.y));
    sep.setPosition(c.res.x/2.0f - c.res.x/200.f, 0);
    // Start rendering
    RenderWindow app(VideoMode(c.res.x, c.res.y), windowTitle);
    app.setFramerateLimit(c.fps);
    while(app.isOpen()) {
        Event event;
        while(app.pollEvent(event)) {
            if(event.type == Event::Closed) {
                app.close();
            }
        }
        if(c.enableLeftBot) {
            leftPaddleBot.movePaddle();
        } else {
            if(Keyboard::isKeyPressed(Keyboard::Up)) leftPaddle.move(leftPaddle.up);
            else if(Keyboard::isKeyPressed(Keyboard::Down)) leftPaddle.move(leftPaddle.down);
            else leftPaddle.stop();
        }

        if(c.enableRightBot) {
            rightPaddleBot.movePaddle();
        } else {
            if(Keyboard::isKeyPressed(Keyboard::W)) rightPaddle.move(rightPaddle.up);
            else if(Keyboard::isKeyPressed(Keyboard::S)) rightPaddle.move(rightPaddle.down);
            else rightPaddle.stop();
        }

        leftPaddle.update();
        rightPaddle.update();
        ball.update();

        ball.bounce(leftPaddle);
        ball.bounce(rightPaddle);

        app.clear(Color::Black);
        leftPaddle.draw(app);
        rightPaddle.draw(app);
        ball.draw(app);
        ball.showScore(app);
        app.draw(sep);
        app.display();
    }

    return 0;
}
