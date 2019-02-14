#include "FadingRenderWindow.hpp"

FadingRenderWindow::FadingRenderWindow(int _fadeRate)
    :fadeRate(_fadeRate),
     awaitReset(false)
{
    
}

bool FadingRenderWindow::create(int x, int y) {
    // create alphamask
    alphamask.setSize(sf::Vector2f(x, y));
    alphamask.setFillColor(sf::Color(0, 0, 0, fadeRate));
    alphamask.setPosition(0, 0);
    // init self
    if (!sf::RenderTexture::create(x, y)) {
        return false;
    }
    clear(sf::Color::Transparent);
    display();
    return true;
}

void FadingRenderWindow::updateFade() {
    if (!awaitReset) {
        draw(alphamask);
    } else {
        clear(sf::Color::Transparent);
        awaitReset = false;
    }
}

void FadingRenderWindow::reset() {
    awaitReset = true;
}