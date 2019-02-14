#include "GravitySim.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>

// init text
void GravitySim::initText()
{
    textConfig.font.loadFromFile("Resources/Arial.ttf");
    textConfig.characterSize = 20;
    textConfig.color = sf::Color::White;
    setText(timescaleText);
}

void GravitySim::setText(sf::Text& t) 
{
    t.setFont(textConfig.font);
    t.setCharacterSize(textConfig.characterSize);
    t.setColor(textConfig.color);
}

void GravitySim::updateText()
{
    std::ostringstream str;
    str << "fps: " << fps << std::endl;
    str << "tickrate: " << tickrate << std::endl;
    str << "dt: " << dt << std::endl;
    timescaleText.setString(str.str());
}

void GravitySim::drawText()
{
    app.draw(timescaleText);
}