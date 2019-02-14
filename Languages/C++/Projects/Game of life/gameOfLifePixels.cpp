#include <SFML/Graphics.hpp>
#include <vector>
#include <stdlib.h>

using std::vector;
using sf::Vertex;
using sf::Vector2f;
using sf::Color;


// res
const int WIDTH = 800;
const int HEIGHT = 450;
// pixel position
const int totalPixels = WIDTH*HEIGHT;
const int padding = 5;
// render type
const Vector2f res(WIDTH+2*padding, HEIGHT+2*padding);
vector<Vertex> grid(WIDTH*HEIGHT);
vector<Vertex> copy(WIDTH*HEIGHT);
// render settings
const float fps = 30;
const float dt = 1/fps;

// function prototypes
bool checkCell(int, int);
float random(float, float);
int getTotalNeighbours(int, int);
void init();
void update();

// main entry point
int main(int argc, char *argv[])
{
    init();
    // make window
    sf::RenderWindow app(sf::VideoMode(res.x, res.y), "Conway's Game of Life");
    app.setFramerateLimit(fps);
    // button input
    float delay = 0;
    float cooldown = 0.5;
    // render
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
        if(delay <= 0)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                init();
                delay = cooldown;
            }
        }
        else
        {
            delay -= dt;
        }
        update();
        app.clear(Color::Black);
        app.draw(grid.data(), grid.size(), sf::Points);
        app.display();
    }


    return 0;
}


// functions
float random(float M, float N)
{
    return M + (rand() / ( RAND_MAX / (N-M) ) ) ;  
}

bool checkCell(int row, int col) 
{
    int cell = row*WIDTH+col;
    if(cell < 0 || cell >= totalPixels) 
    {
        return false;
    }
    Color color = grid[cell].color;
    if(color != Color::Black && color != Color::Red)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void init()
{
    srand(time(NULL));
    for(int row = 0; row < HEIGHT; row++)
    {
        for(int col = 0; col < WIDTH; col++) 
        {
            int cell = row*WIDTH+col;
            // set color
            if(random(0, 1) <= 0.5)
            {
                grid[cell].color = Color::White;
                copy[cell].color = Color::White;
            }
            else
            {
                grid[cell].color = Color::Black;
                copy[cell].color = Color::Black;
            }
            // set coordinates
            grid[cell].position = Vector2f(col+padding, row+padding);
            copy[cell].position = Vector2f(col+padding, row+padding);
        }
    }
}

int getTotalNeighbours(int row, int col)
{
    int totalNeighbours = 0;
    for(int i = row-1; i <= row+1; i++)
    {
        for(int j = col-1; j <= col+1; j++)
        {
            if(i == row  && j == col)
            {
                continue;
            }
            
            if(checkCell(i, j))
            {
                totalNeighbours += 1;
            }
        }
    }
    return totalNeighbours;
}

void update()
{
    for(int row = 0; row < HEIGHT; row++)
    {
        for(int col = 0; col < WIDTH; col++)
        {
            int cell = row*WIDTH+col;
            int totalNeighbours = getTotalNeighbours(row, col);
            bool state = checkCell(row, col);
            if(state)
            {
                // alive and dies
                if(totalNeighbours <= 1 ||  totalNeighbours >= 4)
                {
                    copy[cell].color = Color::Red;
                }
                else
                {
                    copy[cell].color = Color::White;
                }
            }
            else
            {
                // dead and lives
                if(totalNeighbours == 3)
                {
                    copy[cell].color = Color::Green;
                }
                else
                {
                    copy[cell].color = Color::Black;
                }
            }
        }
    }
    // swap references
    vector<Vertex>& temp = grid;
    grid = copy;
    copy = temp;
}