#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <math.h>

using namespace sf;
using namespace std;

typedef struct {
    std::vector<Vertex> points;
    float xScale;
    float yScale;
} Graph;

float foo(float x)
{
    float result = sin(x) + cos(2*x) * sin(3*x);
    return result;
}

void addData(Graph& g, float val)
{
    g.points.erase(g.points.begin());
    for(auto& v: g.points) 
    {
        v.position.x -= g.xScale;
    }
    Vertex v(Vector2f(1300, g.yScale*val+350), Color::White);
    g.points.push_back(v);
}

int main(int argc, char *argv[])
{
    // Triangle gradient shape
    // create an array of 3 vertices that define a triangle primitive
    VertexArray triangle(Triangles, 3);

    // define the position of the triangle's points
    triangle[0].position = Vector2f(100, 100);
    triangle[1].position = Vector2f(1000, 100);
    triangle[2].position = Vector2f(550, 600);

    // define the color of the triangle's points
    triangle[0].color = Color::Red;
    triangle[1].color = Color::Blue;
    triangle[2].color = Color::Green;

    int scale = 50;
    float detail = 10;
    int totalPoints = 1300 / scale * detail;

    Graph g;
    g.points = std::vector<Vertex>(totalPoints);
    g.xScale = scale / detail;
    g.yScale = scale;
    for(int i = 0, len = g.points.size(); i < len; i++)
    {
        Vertex& v = g.points[i];
        float x = g.xScale * i;
        v.position = Vector2f(x, 0+350);
        v.color = Color::White;
    }

    RenderWindow app(VideoMode(1300, 700), "Vertex Test");
    app.setFramerateLimit(30);
    while(app.isOpen()) 
    {
        Event event;
        while(app.pollEvent(event)) 
        {
            if(event.type == Event::Closed) 
            {
                app.close();
            }
        }
        app.clear(Color::Black);
        //app.draw(triangle);
        if(Keyboard::isKeyPressed(Keyboard::Up))
        {
            addData(g, 1);
        }
        else if(Keyboard::isKeyPressed(Keyboard::Down)) 
        {
            addData(g, -1);
        }
        else
        {
            addData(g, 0);
        }
        app.draw(g.points.data(), g.points.size(), LinesStrip);
        app.display();
    }
    
    return 0;
}