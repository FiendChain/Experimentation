#ifndef _GAME_H_
#define _GAME_H_
#include "../Ball/Ball.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <random>

#define TOTAL_CORES 6


class Game {
    public:
        Game(unsigned int fps, unsigned int width, unsigned int height);
        int run();
    private:
        sf::RenderWindow window;
        sf::Vector2u dimensions;
        // randomiser
        std::mt19937 rng_engine;
        void init_rng_engine();
        void randomise_objects();
        // physics properties
        sf::Clock clock;
        float frame_duration;
        float dt;
        void setFrameRate(unsigned int fps);
        // main thread
        void render();
        void get_inputs();
        void recolour_balls(); // recolouring on main thread since waiting for input
        // main balls - main thread
        std::vector<Ball> main_balls;
        void update_main_balls();
        // balls - independent threads
        std::vector<Ball> balls;
        void init_two_way_physics_threads();
        void init_distributed_physics_threads();
        void multithreaded_two_way_physics(int start, int end);
        void multithreaded_distributed_physics(int start, int end);
        // threads
        std::vector<sf::Thread *> two_way_physics_threads;
        std::vector<sf::Thread *> distributed_physics_threads;
        sf::Mutex mutex;
};

#endif