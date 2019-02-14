#include "App.hpp"

#include <SFML/Graphics.hpp>

// run
void App::run() {
    sf::Thread updateThread(&App::update, this);
    updateThread.launch();
    while (window.isOpen()) {
        getInputs();
        render();    
    }
}

void App::render() {
    window.clear(sf::Color::Black);
    // render double buffer
    const sf::Texture &linesTexture = linesBuffer.getTexture();
    sf::Sprite linesSprite(linesTexture);
    window.draw(linesSprite);
    // render balls and active line
    window.draw(connector);
    if (showBalls) {
        for (Ball &ball: balls) {
            window.draw(ball);
        }   
    }
    if (showOverlay) {
        window.draw(overlay);
    }
    // display
    window.display();
}



