#include "../Ball/BallPhysics.hpp"
#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include <functional>
#include <vector>

// distributed non inter-interactive physics
// balls dont interact with each only, only independently
void Game::init_distributed_physics_threads() {
    int total_balls = balls.size();
    int total_threads = TOTAL_CORES-1;
    // only multicore if enough balls
    if (total_balls >= total_threads*10) {
        int balls_per_thread = total_balls/(float)total_threads;
        // create threads
        int current_ball = 0;
        for(int curr_thread = 0; curr_thread < total_threads; curr_thread++) {
            // if last thread, assign remaining balls
            if (curr_thread == total_threads-1) {
                sf::Thread *thread = new sf::Thread(
                    std::bind(&Game::multithreaded_distributed_physics,
                            this, current_ball, total_balls)
                );
                distributed_physics_threads.push_back(thread);
                break;
            }
            // otherwise, increment
            if (current_ball+balls_per_thread <= total_balls) {
                sf::Thread *thread = new sf::Thread(
                    std::bind(&Game::multithreaded_distributed_physics, 
                            this, current_ball, current_ball+balls_per_thread)
                );
                distributed_physics_threads.push_back(thread);
                current_ball += balls_per_thread;
            } else {
                throw "Upper range of distributed physics is greater than array size";
            }
        }
    // if not enough balls, launch single thread
    } else {
        sf::Thread *thread = new sf::Thread(
            std::bind(&Game::multithreaded_distributed_physics, this, 0, total_balls)
        );
        distributed_physics_threads.push_back(thread);
    }
    
    // launch the threads
    for (sf::Thread *thread: distributed_physics_threads) {
        thread->launch();
    }
}

void Game::multithreaded_distributed_physics(int start, int end) {
    // DEBUGGING STUFF
    mutex.lock();
    printf("distributed_threading [%d-%d]/%d\n", start, end, balls.size());
    mutex.unlock();
    // rendering stuff
    sf::Time last_render = clock.getElapsedTime();
    while (1) {
        if((clock.getElapsedTime() - last_render).asSeconds() > frame_duration) {
            last_render = clock.getElapsedTime();
            apply_surface_gravity(balls, start, end);
            bounce_inside_box(balls, dimensions, start, end);
            // wrap_around_box(balls, dimensions, start, end);
            update_balls(balls, start, end, dt);
        }
    }
}