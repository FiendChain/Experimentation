#ifndef _GRAVITY_SIM_H_
#define _GRAVITY_SIM_H_

#include <SFML/Graphics.hpp>
#include <vector>
#include "../Body/Body.hpp"

class GravitySim {
    public:
        // constructor and destructors
        GravitySim(int width, int height, int fps, float tickrate);
        ~GravitySim();
        bool run();
        void addBody(Body b);
    private:
        std::vector<Body> bodies;
        // sim gravity
        sf::Vector2f gravityEquation(Body& a, Body& b);
        void updateBodies();
        float G;
        // remove collided bodies
        bool collideBodies(Body& a, Body &b);
        // physics timescale
        int fps;
        float tickrate;
        float dt;
        // render window
        sf::RenderWindow app;
        void draw();
        void translate(float x, float y);
        // gui
        struct {
            sf::Font font;
            int characterSize;
            sf::Color color;
        } textConfig;
        sf::Text timescaleText;
        void initText();
        void setText(sf::Text& t);
        void updateText();
        void drawText();
        // controls
        struct {
            float delay;
            float cooldown;
        } inputTimer;
        void getInput();
        // debug
        sf::CircleShape getCOM();
};

#endif