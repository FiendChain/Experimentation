#include "GravitySim.hpp"
#include <SFML/Graphics.hpp>

// draw everything
void GravitySim::draw()
{
    app.clear(sf::Color::Black);
    drawText();
    for(auto& b: bodies)
    {
        app.draw(b);
    }
    for(auto& a: bodies)
    {
        for(auto& b: bodies)
        {
            if(&a != &b)
            {
                sf::Vector2f force = gravityEquation(a, b);
                sf::Vector2f tail(a.getPosition());
                sf::Vector2f head(a.getPosition() + 10.0f*force);
                sf::VertexArray v(sf::LinesStrip, 2);
                v[0].position = tail;
                v[0].color = sf::Color::White;
                v[1].position = head; 
                v[1].color = sf::Color::White;
                app.draw(v);
            }
        }
    }
    app.draw(getCOM());
    app.display();
}

// translate window
void GravitySim::translate(float x, float y)
{
    for(auto& b: bodies)
    {
        b.setPosition(b.getPosition()+sf::Vector2f(x, y));
    }
}
