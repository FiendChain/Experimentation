#ifndef _BALL_H_
#define _BALL_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Ball: public sf::CircleShape {
    public:
        Ball();
        Ball(float radius);
        void applyForce(float x, float y);
        void applyAcceleration(float x, float y);
        void update(float dt);
        // modift properties
        void setRadius(float radius);
        void setVelocity(float x, float y);
        sf::Vector2f getVelocity();
        float getMass();
    private:
        // ball physics properties
        const float density = 0.5f;
        float mass;
        // physics data
        sf::Vector2f velocity;
        sf::Vector2f acceleration;
};

#endif