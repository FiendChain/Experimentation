#ifndef _GRAVITY_H_
#define _GRAVITY_H_

#define _USE_MATH_DEFINES
#include <math.h>
#include "Ball.hpp"
#include <vector>

const float GRAVITATION_CONSTANT = 20.0f;
const float MIN_ORBITAL_DISTANCE = 10.0f;
const float MIN_ORBITAL_DISTANCE_SQUARED = (MIN_ORBITAL_DISTANCE*MIN_ORBITAL_DISTANCE);

const float EARTH_SURFACE_GRAVITY = 9.81f;

// update balls
void update_balls(std::vector<Ball> &balls, int start, int end, float dt);
// orbital mechanics
void apply_orbital_gravity(std::vector<Ball> &balls, int start, int end);
void apply_gravity_between_two_balls(Ball &ball_M, Ball &ball_m);
// surface gravity
void apply_surface_gravity(std::vector<Ball> &balls, int start, int end);
// collisions
void apply_collisions(std::vector<Ball> &balls, int start, int end);
void apply_collisions_between_two_balls(Ball &ball_A, Ball &ball_B);
// bounce inside box
void bounce_inside_box(std::vector<Ball> &balls, sf::Vector2u &dimensions, int start, int end);
// wrap box
void wrap_around_box(std::vector<Ball> &balls, sf::Vector2u &dimensions, int start, int end);

#endif


