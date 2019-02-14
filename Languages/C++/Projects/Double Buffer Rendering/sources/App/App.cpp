#include "App.hpp"

App::App(int width, int height, int fps, int _totalBalls) 
    :window(sf::VideoMode(width, height), "Double Buffer", sf::Style::Fullscreen),
     connector(sf::LinesStrip, _totalBalls+1),
     totalBalls(_totalBalls),
     linesBuffer(5),
     showBalls(true),
     showOverlay(false),
     delayMultiplier(4)     // delayMultiplier*dt = time taken for connector render
{
    // set first
    setResolution(width, height);
    setFps(fps);
    // init everything
    init();
}

// fps
void App::setFps(int _fps) {
    fps = _fps;
    dt = 1.0/(float)_fps;
    window.setFramerateLimit(_fps);
}

int App::getFps() {
    return fps;
}

// resolution
void App::setResolution(int width, int height) {
    resolution.x = width;
    resolution.y = height;
}

sf::Vector2u App::getResolution() {
    return resolution;
}