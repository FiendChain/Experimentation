#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <functional>

#define TICK_RATE 3.0f

Game::Game(unsigned int fps, unsigned int width, unsigned int height)
    : window(sf::VideoMode(width, height), "Game"),
      dimensions(width, height)
{
    setFrameRate(fps);
    init_rng_engine();
    randomise_objects();
}

void Game::setFrameRate(unsigned int fps) {
    window.setFramerateLimit(fps);
    frame_duration = 1/(float)fps;
    dt = TICK_RATE/(float)fps;
}


