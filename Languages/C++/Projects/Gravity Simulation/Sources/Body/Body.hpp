#ifndef _BODY_H_
#define _BODY_H_

#include <SFML/Graphics.hpp>

class Body: public sf::CircleShape {
    public:
        bool fixed;

        Body(
            float mass, 
            float radius
        );
        // setters
        void setVelocity(float x, float y);
        void setVelocity(sf::Vector2f vel);
        // getters
        sf::Vector2f getVelocity();
        sf::Vector2f getAcceleration();
        // physics
        void applyForce(sf::Vector2f acc); 
        void update(float dt=1);
        float getMass();
    private:
        float mass;
        // setRadius(float radius)
        // setPosition(sf::Vector2f pos)
        // setPosition(float x, float y)
        sf::Vector2f vel;
        sf::Vector2f acc;
};

#endif