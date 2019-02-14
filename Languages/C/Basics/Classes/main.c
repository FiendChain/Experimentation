#include "classes.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define BREAK_SECTION "\n========================================\n"
#define MAX_PARTICLES 100

// Prototypes
void appendList(particle_t *particleList[MAX_PARTICLES], particle_t *newParticle);
void printList(particle_t *particleList[MAX_PARTICLES]);
particle_t consoleParticle(void);
char *scientificNotation(double number);

int main(void) {
    // Instantiating multiple particles : createParticle(name, mass, posX, posY, velX, velY)
    particle_t boson = createParticle("Boson", 5, 20, 20, 100, 100);
    particle_t meson = createParticle("Meson", 10, 20, 30, 100, 50);
    particle_t proton = createParticle("Proton", 10, 201, 35, 120, 0);
    particle_t neutron = createParticle("Neutron", 0, 0, 0, 0, 0);
    // Creating list of particles
    particle_t *particleList[MAX_PARTICLES] = {&boson, &meson, &proton, &neutron};
    

    // Creating an instance from console
    //particle_t newParticle = consoleParticle();
    //appendList(particleList, &newParticle);

    // Testing update method on all particles in list
    for(int i = 0; particleList[i] != NULL; i ++) {
        particleList[i] -> update(particleList[i], 10);
    }
    printList(particleList);

    return 0;
}

// Append to particle list
void appendList(particle_t *particleList[MAX_PARTICLES], particle_t *newParticle) {
    int i = 0;
    while(particleList[i] != NULL) {
        i += 1;
    }
    if(i != MAX_PARTICLES - 1) {
        particleList[i] = newParticle;
    }
}

// Print a list
void printList(particle_t *particleList[MAX_PARTICLES]) {
    for(int i = 0; particleList[i] != NULL; i ++) {
        printf(BREAK_SECTION);
        particleList[i] -> self(particleList[i]);
    }
}

// Fetch particle from console
particle_t consoleParticle(void) {
    particle_t particle = createParticle(NULL, 0, 0, 0, 0, 0);
    printf("Enter name of particle [Max=100]: ");
    scanf("%s", particle.name);
    printf("Enter mass of particle: ");
    scanf("%lf", &particle.mass);
    printf("Enter [x][y] position: ");
    scanf("%lf %lf", &particle.pos.x, &particle.pos.y);
    printf("Enter [x][y] velocity: ");
    scanf("%lf %lf", &particle.vel.x, &particle.vel.y);

    return particle;
}

// Return sci-notation for number
char *sciNot(double number) {
    if(isnan(number)) {
        return "NaN";
    }

    int totalPowers = 0;
    if(number > 10) {
        while(number > 10) {
            totalPowers ++;
            number /= 10;
        }
    } else if(number != 0) {
        while(number < 10) {
            totalPowers --;
            number *= 10;
        }
    }

    char *result = malloc(20 *sizeof(char));
    if(totalPowers != 0) {
        sprintf(result, "%.2lf x 10^%d", number, totalPowers);
    } else {
        sprintf(result, "%.2lf", number);
    }
    
    return result;
}