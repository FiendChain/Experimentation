#ifndef _APP_H_
#define _APP_H_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

#include "../Ball/Ball.hpp"
#include "../RainbowColour/RainbowColour.hpp"
#include "../FadingRenderWindow/FadingRenderWindow.hpp"

class App {
    public:
        App(int width, int height, int fps, int _totalBalls);
        void run();
    private:
        // properties
        int fps;
        float dt;
        int totalBalls;
        int delayMultiplier;
        sf::Clock clock;
        sf::Vector2u resolution;
        // game flags
        bool showBalls;
        bool showOverlay;
        // resources
        FadingRenderWindow linesBuffer;
        sf::RenderWindow window;
        sf::Text overlay;
        sf::Font font;
        // objects
        std::vector<Ball> balls;
        sf::VertexArray connector;
        RainbowColour rainbow;
        // main thread
        void render();
        void getInputs();
        void inputBindings(sf::Keyboard::Key key);
        void update();
        // update 
        void updatePhysics();
        void updateLinesBuffer();
        void updateConnector();
        void updateOverlay();
        // init
        void init();
        void initBalls();
        void initLinesBuffer();
        void initConnector();
        void initOverlay();
        void initFont();
        // randomiser
        std::mt19937 rng_engine;
        void initRngEngine();
        // setters and getters
        void setFps(int _fps);
        int getFps();
        void setResolution(int width, int height);
        sf::Vector2u getResolution();

};

#endif