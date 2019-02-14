#include "pong.hpp"
#include <iostream>

using pong::PaddleBot;
using pong::Ball;
using pong::Paddle;

PaddleBot::PaddleBot(Ball &ballSet, Paddle &paddleSet, int skillSet)
    : ball(ballSet), paddle(paddleSet) { // Reference member initialisation
    skill = skillSet;
    inPosition = false;
}

float PaddleBot::predictCollision() {
    // Equation variables  
    float m = ball.vel.y / ball.vel.x;
    float b = ball.pos.y - m * ball.pos.x;
    float x = paddle.pos.x;
    // Paddle and ball dimensions
    float width = paddle.width / 2.0f;
    float radius = ball.radius;
    // Box height
    float maxHeight = ball.res.y;
    int dir;
    // Left side
    if(ball.vel.x < 0) {
        dir = -1;
    } else {
        dir = 1;
    }
    float y = maxHeight/2.0f;
    for(int i = 0; i < skill; i++) {
        // Get prediction
        if(dir < 0) {             
            y = m*(x+width) + b;
        } else {
            y = m*(x-width) + b;
        }
        // Check if within bounds
        if(y < maxHeight && y > 0) {    
            break;
        }
        // Shift the prediction line
        if(m*dir >= 0) {
            b = 2*(maxHeight - radius) - b;
        } else {
            b = 2*(0+radius) - b;
        }
        m *= -1;
    }
    // If prediction out of bounds, track ball
    if(y > maxHeight || y < 0) {
        y = ball.pos.y;
    }

    return y;
}

bool PaddleBot::checkDirection() {
    float xDiff = paddle.pos.x - ball.pos.x;
    if(xDiff * ball.vel.x < 0) {
        return false;
    }
    return true;
}

void PaddleBot::movePaddle() {
    if(checkDirection()) {
        float y = predictCollision();
        // If not in middle position, get to middle segment
        if(!inPosition) {
            if(y > paddle.pos.y + paddle.height/3.0f) {
                paddle.move(Paddle::down);
            } else if(y < paddle.pos.y - paddle.height/3.0f) {
                paddle.move(Paddle::up);
            } else {
                paddle.stop();
                inPosition = true;
            }
        } else {
            if(y > paddle.pos.y + paddle.height/2.0f) {
                inPosition = false;
            } else if(y < paddle.pos.y - paddle.height/2.0f) {
                inPosition = false;
            }
        }
    }
}




