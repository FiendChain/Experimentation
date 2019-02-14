#include "../Ball/Ball.hpp"
#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include <random>

void Game::init_rng_engine() {
    std::random_device rng_source;
    std::mt19937 engine(time(NULL));
    rng_engine = engine;
}

// randomise balls
void Game::randomise_objects() {
    // generate balls
    std::uniform_real_distribution<float> pos_x(0, dimensions.x),
                                          pos_y(0, dimensions.y),
                                          vel_x(-100, 100),
                                          vel_y(-100, 100),
                                          size(10, 50),
                                          colour(0, 256);
    int total_balls = 200;
    for (int i = 0; i < total_balls; i++) {
        Ball ball(size(rng_engine));
        ball.setPosition(pos_x(rng_engine), pos_y(rng_engine));
        ball.setVelocity(vel_x(rng_engine), vel_y(rng_engine));
        ball.setFillColor(sf::Color(colour(rng_engine), 
                                    colour(rng_engine), 
                                    colour(rng_engine),
                                    colour(rng_engine)));
        balls.push_back(ball);
    }
    // create main balls
    int total_main_balls = 1;
    for (int i = 0; i < total_main_balls; i++) {
        Ball ball(100);
        ball.setPosition(pos_x(rng_engine), pos_y(rng_engine));
        ball.setVelocity(vel_x(rng_engine), vel_y(rng_engine));
        ball.setFillColor(sf::Color(255, 255, 255, 150));
        main_balls.push_back(ball);
    }
}