#include "BallPhysics.hpp"
#include <SFML/Graphics.hpp>

void apply_physics_to_balls(std::vector<Ball> &balls, 
                            int start, int end, 
                            void (*func)(Ball &, Ball &));

// update balls
void update_balls(std::vector<Ball> &balls, int start, int end, float dt) {
    for (int i = start; i < end; i++) {
        Ball &ball = balls.at(i);
        ball.update(dt);
    }
}

// orbital mechanics
void apply_orbital_gravity(std::vector<Ball> &balls, int start, int end) {
    apply_physics_to_balls(balls, start, end, &apply_gravity_between_two_balls);
}

void apply_gravity_between_two_balls(Ball &ball_M, Ball &ball_m) {
    sf::Vector2f diff = ball_M.getPosition() - ball_m.getPosition();
    float distance_squared = diff.x*diff.x + diff.y*diff.y;
    float distance;
    if (distance_squared < MIN_ORBITAL_DISTANCE_SQUARED) {
        distance_squared = MIN_ORBITAL_DISTANCE_SQUARED; 
        distance = MIN_ORBITAL_DISTANCE;
    } else {
        distance = pow(distance_squared, 0.5f);
    }
    
    float force = (GRAVITATION_CONSTANT*ball_M.getMass()*ball_m.getMass())/distance_squared;
    sf::Vector2f force_ball_m = diff*(force/distance); 
    ball_m.applyForce(force_ball_m.x, force_ball_m.y);
    ball_M.applyForce(-force_ball_m.x, -force_ball_m.y); // newton's third law
}

// collision physics
void apply_collisions(std::vector<Ball> &balls, int start, int end) {
    apply_physics_to_balls(balls, start, end, &apply_collisions_between_two_balls);
}

void apply_collisions_between_two_balls(Ball &ball_A, Ball &ball_B) {
    // only update if there is a collision
    sf::Vector2f diff = ball_A.getPosition() - ball_B.getPosition();
    float distance_squared = diff.x*diff.x + diff.y*diff.y;
    float distance = pow(distance_squared, 0.5f);
    if (distance > (ball_A.getRadius() + ball_B.getRadius())) {
        return;
    }
    // get collision force
    sf::Vector2f velocity_diff = ball_A.getVelocity() - ball_B.getVelocity();
    float speed_squared = velocity_diff.x*velocity_diff.x + velocity_diff.y*velocity_diff.y;
    float speed = pow(speed_squared, 0.5f);
    float force = speed*(ball_A.getMass() + ball_B.getMass()); 
    sf::Vector2f force_ball_A = diff*(force/distance); 
    ball_A.applyForce(force_ball_A.x, force_ball_A.y);
    ball_B.applyForce(-force_ball_A.x, -force_ball_A.y); // newton's third law
}

// iterate over a set of balls and apply a function
// used for interactions between all ball objects
void apply_physics_to_balls(std::vector<Ball> &balls, 
                            int start, int end, 
                            void (*func)(Ball &, Ball &)) 
{
    const int total_balls = balls.size();
    for (int i = start; i < end; i++) {
        Ball &ball_A = balls.at(i);
        for (int j = i+1; j < total_balls; j++) {
            Ball &ball_B = balls.at(j);
            (*func)(ball_A, ball_B);
        }
    }
}

// surface gravity
void apply_surface_gravity(std::vector<Ball> &balls, int start, int end) {
    for (int i = start; i < end; i++) {
        Ball &ball = balls.at(i);
        ball.applyAcceleration(0, EARTH_SURFACE_GRAVITY);
    }
}

// bounce inside box
void bounce_inside_box(std::vector<Ball> &balls, sf::Vector2u &dimensions, int start, int end) {
    for (int i = start; i < end; i++) {
        Ball &ball = balls.at(i);
        // perform bounces
        sf::Vector2f position = ball.getPosition();
        sf::Vector2f velocity = ball.getVelocity();
        float radius = ball.getRadius();
        // bounce for x
        if (position.x - radius < 0 && velocity.x < 0) {
            position.x = radius;
            velocity.x = -velocity.x;
        } else if (position.x + radius > dimensions.x && velocity.x > 0) {
            position.x = dimensions.x - radius;
            velocity.x = -velocity.x;
        }
        // bounce for y
        if (position.y + radius > dimensions.y && velocity.y > 0) {
            position.y = dimensions.y-radius;
            velocity.y = -velocity.y;
        } else if (position.y - radius < 0 && velocity.y < 0) {
            position.y = radius;
            velocity.y = -velocity.y;
        }
        ball.setPosition(position);
        ball.setVelocity(velocity.x, velocity.y);
    }
    
}

// wrap around box like torus
void wrap_around_box(std::vector<Ball> &balls, sf::Vector2u &dimensions, int start, int end) {
    for (int i = start; i < end; i++) {
        Ball &ball = balls.at(i);
        sf::Vector2f position = ball.getPosition();
        // x wrap
        if (position.x < 0) {
            position.x = dimensions.x;
        } else if (position.x > dimensions.x) {
            position.x = 0;
        }
        // y wrap
        if (position.y < 0) {
            position.y = dimensions.y;
        } else if (position.y > dimensions.y) {
            position.y = 0;
        }
        // apply position
        ball.setPosition(position);
    }
}