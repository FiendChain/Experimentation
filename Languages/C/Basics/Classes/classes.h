// Creating structures
typedef struct _particle particle_t;
typedef struct _vector vector_t;
typedef struct _physic physic_t;

struct _physic {
    double (*kineticEnergy)(particle_t *);
    double (*restEnergy)(particle_t *);
    double (*momentum)(particle_t *);
    void (*info)(particle_t *);
};

struct _vector {
    double x;
    double y;
    char *units;
    double (*mag)(vector_t *);
    double (*dir)(vector_t *);
    void (*info)(vector_t *);
};

struct _particle {
    char *name;
    double mass;
    vector_t pos;
    vector_t vel;
    physic_t physic;
    void (*self)(particle_t *);
    void (*update)(particle_t *, double);
};

// Vector method prototypes
double magnitude(vector_t *vector);
double direction(vector_t *vector);
void vectorInfo(vector_t *vector);

// Particle method prototypes
void description(particle_t *particle);
void update(particle_t *particle, double time);

// Physics method prototypes
double kineticEnergy(particle_t *particle);
double restEnergy(particle_t *particle);
double momentum(particle_t *particle);
void physicInfo(particle_t *particle);

// Functions to create classes 
particle_t createParticle(
    char *name, double mass, 
    double posX, double posY, 
    double velX, double velY);
vector_t createVector(double x, double y, char *units);
physic_t createPhysic(void);

// Scientific notation
char *sciNot(double number);