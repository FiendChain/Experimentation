#include "../Ball/BallPhysics.hpp"
#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include <functional>
#include <vector>

// two way physics
void Game::init_two_way_physics_threads() {
    int total_balls = balls.size();
    // only multitask for sufficient number of balls
    if (total_balls > 30) {
        int total_interactions = (total_balls/2.0)*(total_balls-1); // forms a triangle
        int total_cores = TOTAL_CORES-1; // leave cores for input and main_ball
        int approximate_ball_share = total_interactions / (float)total_cores;
        // get distribution of balls for each thread
        int current_ball = 0;
        int total_interaction_for_thread = 0;
        for (int curr_thread = 0; curr_thread < total_cores; curr_thread++) {
            // if last thread, make it take the remaining cores
            if (curr_thread == total_cores-1) {
                sf::Thread *thread = new sf::Thread(std::bind(&Game::multithreaded_two_way_physics, this, current_ball, total_balls));
                two_way_physics_threads.push_back(thread);
                break;
            }
            // otherwise, allocate balls evenly according to total interactions
            for (int i = current_ball; i < total_balls; i++) {
                // if overflow about to occur
                // assign the thread
                if (total_interaction_for_thread + (total_balls-1-i) > approximate_ball_share) {
                    sf::Thread *thread = new sf::Thread(std::bind(&Game::multithreaded_two_way_physics, this, current_ball, i));
                    two_way_physics_threads.push_back(thread);
                    current_ball = i;
                    total_interaction_for_thread = 0;
                    break;
                // otherwise, continue allocation
                } else {
                    total_interaction_for_thread += (total_balls-1-i);
                }
            }
        }
    // use single thread for low number of balls
    } else {
        sf::Thread *thread = new sf::Thread(std::bind(&multithreaded_two_way_physics, this, 0, total_balls));
        two_way_physics_threads.push_back(thread);
    }
    // launch threads
    for (sf::Thread *thread: two_way_physics_threads) {
        thread->launch();
    }       
}

void Game::multithreaded_two_way_physics(int start, int end) {
    // DEBUGGING STUFF
    mutex.lock();
    printf("two_way_threading [%d-%d]/%d\n", start, end, balls.size());
    mutex.unlock();
    // rendering stuff
    sf::Time last_render = clock.getElapsedTime();
    while (1) {
        if((clock.getElapsedTime() - last_render).asSeconds() > frame_duration) {
            last_render = clock.getElapsedTime();
            // apply_orbital_gravity(balls, start, end);
            // apply_surface_gravity(balls, start, end);
            apply_collisions(balls, start, end);
            // wrap_around_box(balls, dimensions, start, end);
            bounce_inside_box(balls, dimensions, start, end);
            update_balls(balls, start, end, dt);
        }
    }
}