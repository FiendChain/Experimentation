// Creating a class in c++
#include <iostream> // std::cout
#include <vector>   // std::vector
#include <sstream>  // std::ostreamstring
#include <string>   // std::string

// Graphics library
#include <SFML/Graphics.hpp>

using namespace std;    // Allows use to use standard stuff?
using namespace sf;

class Vector {
    public:
        float x;
        float y;

        // Initialisation
        Vector() {  // Default constructor
            x = 0;
            y = 0;
        }

        Vector(float xSet, float ySet) {
            x = xSet;
            y = ySet;
        }

        void set(float xSet, float ySet) {
            x = xSet;
            y = ySet;
        }

        // Methods
        void add(Vector vector) {
            x += vector.x;
            y += vector.y;
        }

        void sub(Vector vector) {
            x -= vector.x;
            y -= vector.y;
        }

        void mult(float scalar) {
            x *= scalar;
            y *= scalar;
        }

        Vector getScale(float scalar) {
            return Vector(x*scalar, y*scalar);
        }

        string describe() {
            ostringstream str;
            str << "x: " << x << ", y: " << y;
            return str.str();
        }
};

class Particle {
    public:
        Vector pos; 
        Vector vel;
        Vector acc;
        float dt;

        // Default constructor
        Particle() {
            dt = 1;
        }

        Particle(Vector posSet, Vector velSet, Vector accSet) {
            pos = posSet;
            vel = velSet;
            acc = accSet;
            dt = 1;
        }

        void applyForce(float x, float y) {
            acc.set(x, y);
        }

        void applyForce(Vector vector) {
            acc = vector;
        }

        void update() {
            vel.add(acc.getScale(dt));
            pos.add(vel.getScale(dt));
            acc.mult(0);
        }

        void show(RenderWindow &app) {
            CircleShape shape(20);
            shape.setFillColor(Color(255, 255, 255));
            shape.setPosition(pos.x, pos.y);
            app.draw(shape);
        }

        // Create a string in c++
        string describe() {
            ostringstream str;  // Feed characters into an output stream?
            str << "Pos = { " << pos.describe() << "}" << endl;
            str << "Vel = { " << vel.describe() << "}" << endl;
            str << "Acc = { " << acc.describe() << "}" << endl;
            return str.str();   // Convert into string and return
        }
};

int main(int argc, char *argv[]) {
    int width = 1300;
    int height = 700;
    string windowTitle = "Particle";
    int fps = 100;

    RenderWindow app(VideoMode(width, height), windowTitle);
    app.setFramerateLimit(fps);

    Particle boson;
    boson.dt = 10.0 / (float)fps;
    boson.vel.set(10, 100);

    while(app.isOpen()) {
        Event event;
        while(app.pollEvent(event)) {
            if(event.type == Event::Closed) {
                app.close();
            }
        }
        boson.applyForce(0, -9.8);
        boson.update();

        app.clear(Color::Black);
        boson.show(app);
        app.display();
    }


    return 0;
}