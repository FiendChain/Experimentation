#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <math.h>

typedef struct _Vector Vector;

struct _Vector {
    float x, y, z;
    float (*mag)(Vector *v);
    Vector (*getMult)(Vector *v, float scalar);
    void (*describe)(Vector *v);
    void (*set)(Vector *v,float x, float y, float z);
    void (*add)(Vector *left, Vector *right); // Left += Right
};

float getMag(Vector *v) {
    return pow(v->x*v->x + v->y*v->y + v->z*v->z, 0.5f);
}

void describeVector(Vector *v) {
    printf("{x: %.2lf, y: %.2lf, z: %.2lf}\n", v->x, v->y, v->z);
}

Vector getMultVector(Vector *v, float scalar) {
    Vector new;
    new.x = v->x * scalar;
    new.y = v->y * scalar;
    new.z = v->z * scalar;
    return new;
}

void setVector(Vector *v, float x, float y, float z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

void addVector(Vector *left, Vector *right) {
    left->x += right->x;
    left->y += right->y;
    left->z += right->z;
}

Vector *makeVector(float x, float y, float z) {
    Vector *v = (Vector *)malloc(sizeof(Vector));
    if(v == NULL) {
        error(0, 0, "Not enough memory for Vector");
        exit(EXIT_FAILURE);
    }
    v->x = x, v->y = y, v->z = z;
    v->mag = *getMag;
    v->describe = *describeVector;
    v->getMult = *getMultVector;
    v->set = *setVector;
    v->add = *addVector;

    return v;
}

typedef struct _Particle Particle;

struct _Particle {
    Vector *pos;
    Vector *vel;
    Vector *acc;
    float dt;
    void (*update)(Particle *p);
    void (*describe)(Particle *p);
    void (*free)(Particle *p);
};

void updateParticle(Particle *p) {
    Vector accDt = p->acc->getMult(p->acc, p->dt);
    Vector velDt = p->vel->getMult(p->vel, p->dt);
    p->vel->add(p->vel, &accDt);
    p->pos->add(p->pos, &velDt);
    p->acc->set(p->acc, 0, 0, 0);
}

void describeParticle(Particle *p) {
    printf("acc="); p->acc->describe(p->acc);
    printf("vel="); p->vel->describe(p->vel);
    printf("pos="); p->pos->describe(p->pos);
    printf("dt=%.2f\n", p->dt);
}

void freeParticle(Particle *p) {
    free(p->pos);
    free(p->vel);
    free(p->acc);
    free(p);
    p = NULL;
}

Particle *makeParticle() {
    Particle *p = malloc(sizeof(Particle));
    if(p == NULL) {
        error(0, 0, "Not enough memory for Particle");
        exit(EXIT_FAILURE);
    }
    p->pos = makeVector(0, 0, 0);
    p->vel = makeVector(0, 0, 0);
    p->acc = makeVector(0, 0, 0);
    p->dt = 1;
    p->update = *updateParticle;
    p->describe = *describeParticle;
    p->free = *freeParticle;
}



int main(int argc, char *argv[]) {
    printf("Making a pseudo-Vector class\n");
    Vector *v = makeVector(1, 2, 3);
    v->describe(v);
    printf("Mag v = %.2lf\n", v->mag(v));
    free(v);

    printf("Making a pseudo-Particle class\n");
    Particle *p = makeParticle();
    p->pos->set(p->pos, 1, 2, 3);
    p->vel->set(p->vel, 3, 4, 5);
    p->acc->set(p->acc, 6, 7, 8);
    p->describe(p);
    printf("One update of the particle\n");
    p->update(p);
    p->describe(p);
    p->free(p);

    printf("Making a gravity affected particle\n");
    p = makeParticle();
    p->vel->set(p->vel, 100, 200, 100);
    p->dt = 0.5;
    p->describe(p);
    for(int i = 0; i < 20; i++) {
        p->acc->set(p->acc, 0, -9.8, 0);
        p->update(p);
        printf("Iteration [%d]\n", i);
        p->describe(p);
    }
    //free(p);
    p->free(p);

    return EXIT_SUCCESS;
}