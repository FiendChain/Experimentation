#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <iostream>
#include <math.h>
#include <time.h>

#define GRAVITY_TYPE 1

sf::Vector2f res(1300, 700);

typedef std::vector<sf::Vertex> VertexArray;
const int totalPoints = 10000;
int totalAttractors = 2;
const float G = 150.0f;
const float attractorRadius = 3;
const float randomVel = 5;
const float minRadius = 1000.0f;
float dt = 1;
int fps = 144;
float tickrate = 10.0f;

VertexArray pos(totalPoints);
VertexArray vel(totalPoints);
VertexArray acc(totalPoints);
std::vector<sf::CircleShape> attractors(totalAttractors);
sf::Vector2f circleOffset(attractorRadius, attractorRadius);
sf::CircleShape COM(attractorRadius);

//func proto
float randMToN(float M, float N);
sf::CircleShape makeAttractor();
void init();
void getCOM();
void applyForce();
void update();


float randMToN(float M, float N)
{
    return M + (rand() / ( RAND_MAX / (N-M) ) ) ;  
}

sf::CircleShape makeAttractor()
{
    sf::CircleShape a;
    a.setPosition(sf::Vector2f(randMToN(0, res.x), randMToN(0, res.y)));
    a.setFillColor(sf::Color(0, 255, 0));
    a.setRadius(attractorRadius);
    return a;
}

void init()
{
    for(int i = 0; i < totalPoints; i++)
    {
        pos[i].position = sf::Vector2f(randMToN(0, res.x), randMToN(0, res.y));
        #ifndef GRAVITY_TYPE
        vel[i].position = sf::Vector2f(randMToN(-randomVel, randomVel), randMToN(-randomVel, randomVel));
        #else
        vel[i].position = sf::Vector2f(0, 0);
        #endif
        acc[i].position = sf::Vector2f(0, 0);
        pos[i].color = sf::Color::White;
    }
    // get attractors
    for(auto& a: attractors)
    {
        a = makeAttractor();
    }
    // getCOM
    getCOM();
}

void getCOM()
{
    COM.setPosition(sf::Vector2f(0, 0));
    for(auto& a: attractors)
    {
        COM.setPosition(COM.getPosition() + a.getPosition() + circleOffset);
    }
    COM.setPosition(COM.getPosition() / (float)attractors.size());
    COM.setFillColor(sf::Color::Red);
    COM.setPosition(COM.getPosition() - circleOffset);
}

void applyForce()
{
    for(auto& a: attractors)
    {
        for(int i = 0; i < totalPoints; i++)
        {
            sf::Vector2f dir = (a.getPosition() + circleOffset - pos[i].position);
            float r2 = dir.x*dir.x + dir.y*dir.y;

            // F = G/r^2
            #ifndef GRAVITY_TYPE
            float r3 = (float)pow(r2, 1.5f);
            if(r3 < minRadius) r3 = minRadius;
            acc[i].position += G * dir / r3;

            // F = G*r
            #else
            acc[i].position += G * dir / r2;
            #endif
        }
    }
}

void update()
{
    for(int i = 0; i < totalPoints; i++)
    {
        vel[i].position += acc[i].position * dt;
        pos[i].position += vel[i].position * dt;
        acc[i].position.x = acc[i].position.y = 0;
    }
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    init();
    sf::RenderWindow app(sf::VideoMode(res.x, res.y), "Vertex Physics");
    app.setFramerateLimit(fps);
    // Physics properties
    float frameTime = 1/(float)fps;
    dt = tickrate/(float)fps;
    // Actions
    float delay = 0;
    float cooldown = 0.5f;
    bool paused = false;

    while(app.isOpen())
    {
        sf::Event event;
        while(app.pollEvent(event)) 
        {
            if(event.type == sf::Event::Closed) 
            {
                app.close();
            }
        }
        if(delay <= 0.0f)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                init();
                delay = cooldown;
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                paused = !paused;
                delay = cooldown;
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {

                attractors.push_back(makeAttractor());
                getCOM();
                delay = cooldown;
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                if(attractors.size() > 1)
                {
                    attractors.erase(attractors.end());
                    getCOM();
                    delay = cooldown;
                }
            }
        }
        else
        {
            delay -= frameTime; 
        }
        if(!paused)
        {
            applyForce();
            update();
        }
        app.clear(sf::Color::Black);
        app.draw(pos.data(), pos.size(), sf::Points);
        app.draw(COM);
        for(auto &a: attractors)
        {
            app.draw(a);
        }
        app.display();
    }


    return 0;
}