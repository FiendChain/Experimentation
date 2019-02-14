#include "App.hpp"

#define ALPHA_CHANGE_RATE 10

void App::getInputs() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            inputBindings(event.key.code);
            break;
        }
    }
}

void App::inputBindings(sf::Keyboard::Key key) {
    switch (key) {
    case sf::Keyboard::Escape:
        window.close();
        break;
    // reset screen
    case sf::Keyboard::Space:
        linesBuffer.reset();
        break;
    // toggle balls
    case sf::Keyboard::H:
        showBalls = !showBalls;
        break;
    // change rainbow alpha
    case sf::Keyboard::LBracket:
        if (rainbow.a >= ALPHA_CHANGE_RATE) rainbow.a -= ALPHA_CHANGE_RATE;
        break;
    case sf::Keyboard::RBracket:
        if (rainbow.a <= MAX_RGB_CHANNEL-ALPHA_CHANGE_RATE) rainbow.a += ALPHA_CHANGE_RATE;
        break;
    // toggle overlay
    case sf::Keyboard::P:
        showOverlay = !showOverlay;
        break;
    // delay multiplier
    case sf::Keyboard::Comma:
        if (delayMultiplier > 1) delayMultiplier--;
        break;
    case sf::Keyboard::Period:
        delayMultiplier++;
        break;
    }
}