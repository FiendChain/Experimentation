#include "classes.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAB_SECTION "   "
#define LIGHT_SPEED 300000000

// Vector methods
double magnitude(vector_t *vector) {
    double magSquared = pow(vector -> x, 2) + pow(vector -> y, 2);
    return pow(magSquared, 0.5);
}

double direction(vector_t *vector) {
    double radian = atan(vector -> y / vector -> x);
    double degree = radian * 180/3.14;
    return degree;
}

void vectorInfo(vector_t *vector) {
    double mag = vector -> mag(vector);
    double dir = vector -> dir(vector);
    printf(TAB_SECTION "x: %.3lf\ty: %.3lf\n", vector -> x, vector -> y);
    printf(TAB_SECTION "Magnitude: %s %s\n", sciNot(mag), vector -> units);
    printf(TAB_SECTION "Direction: %.3lf degrees\n", dir);
}

// Particle methods
void description(particle_t *particle) {
    printf(">>Name of particle: %s\n", particle -> name);
    printf("> Mass: %.3lf\n", particle -> mass);
    printf("> Information about position:\n");
    particle -> pos.info(&particle -> pos);
    printf("> Information about velocity:\n");
    particle -> vel.info(&particle -> vel);
    printf("> Energy information: \n");
    particle -> physic.info(particle);
}

void update(particle_t *particle, double time) {
    particle -> pos.x += particle -> vel.x * time;
    particle -> pos.y += particle -> vel.y * time;
}

// Physics methods
double kineticEnergy(particle_t *particle) {
    vector_t *velocity = &(particle -> vel);
    return 0.5 * (particle -> mass) * pow(velocity -> mag(velocity), 2);
}

double restEnergy(particle_t *particle) {
    return (particle -> mass) * pow(LIGHT_SPEED, 2);
}

double momentum(particle_t *particle) {
    vector_t *velocity = &(particle -> vel);
    return (particle -> mass) * (velocity -> mag(velocity));
}

void physicInfo(particle_t *particle) {
    double kineticEnergy = particle -> physic.kineticEnergy(particle);
    double restEnergy = particle -> physic.restEnergy(particle);
    double momentum = particle -> physic.momentum(particle);
    printf(TAB_SECTION "Kinetic Energy: %s joules\n", sciNot(kineticEnergy));
    printf(TAB_SECTION "Rest Energy: %s joules\n", sciNot(restEnergy));
    printf(TAB_SECTION "Momentum: %s kgm\n", sciNot(momentum));
}



