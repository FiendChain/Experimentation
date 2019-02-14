// Creating a class
#include "classes.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING 100

// Creating virtual particle class
particle_t createParticle(
    char *name, double mass, 
    double posX, double posY, 
    double velX, double velY) {
    // Creating particle class
    particle_t particle;
    // Variables
    particle.name = malloc(MAX_STRING *sizeof(char));
    if(name != NULL) {
        particle.name = name;
    }
    particle.mass = mass;
    particle.physic = createPhysic();
    particle.pos = createVector(posX, posY, "m");
    particle.vel = createVector(velX, velY, "m/s");
    // Methods
    particle.self = &description;
    particle.update = &update;


    return particle;
}

 // Creating virtual vector class 
vector_t createVector(double x, double y, char *units) {
    vector_t vector;
    vector.x = x;
    vector.y = y;
    vector.units = malloc(10 * sizeof(char));
    if(units != NULL) {
        vector.units = units;
    }
    vector.mag = &magnitude;
    vector.dir = &direction;
    vector.info = &vectorInfo;
    
    return vector;
}

// Creating virtual physics class
physic_t createPhysic(void) {
    physic_t physic;
    physic.kineticEnergy = &kineticEnergy;
    physic.restEnergy = &restEnergy;
    physic.momentum = &momentum;
    physic.info = &physicInfo;

    return physic;
}