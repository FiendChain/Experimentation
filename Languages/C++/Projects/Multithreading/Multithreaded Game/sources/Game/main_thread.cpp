#include "Game.hpp"
#include "../Ball/BallPhysics.hpp"

// everything here runs on the main thread

// run the game in a loop until closing
int Game::run() {
    // init_two_way_physics_threads();
    init_distributed_physics_threads();
    while (window.isOpen()) {
        render();
        update_main_balls();
        get_inputs();
    }
    return EXIT_SUCCESS;
}

// render all balls
void Game::render() {
    window.clear(sf::Color::Black);
    for (Ball &ball: balls) {
        window.draw(ball); 
    }
    for (Ball &ball: main_balls) {
        window.draw(ball);
    }
    window.display();
}

// recolour balls
void Game::recolour_balls() {
    // recolour balls
    std::uniform_int_distribution<int> colour(0, 256);
    for (Ball &ball: balls) {
        ball.setFillColor(sf::Color(colour(rng_engine), 
                                    colour(rng_engine), 
                                    colour(rng_engine),
                                    colour(rng_engine)));
    }
}

// get inputs
void Game::get_inputs() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            break;
        } else if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
            case sf::Keyboard::Space:
                recolour_balls();
                break;
            }
        }
    }
}

// main balls on main thread
void Game::update_main_balls() {
    const int total_balls = main_balls.size();
    apply_surface_gravity(main_balls, 0, total_balls);
    update_balls(main_balls, 0, total_balls, 3*dt);
    bounce_inside_box(main_balls, dimensions, 0, total_balls);
}