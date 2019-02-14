#include <SFML/Graphics.hpp>
#include <vector>
#include <stdlib.h>

using std::vector;
using sf::Vertex;
using sf::Vector2f;
using sf::Color;

// res
const int WIDTH = 150;
const int HEIGHT = 100;
// pixel position
const int totalPixels = WIDTH*HEIGHT;
const int padding = 5;
// render type
const int pixelSize = 8;
const Vector2f res((WIDTH*pixelSize)+2*padding, (HEIGHT*pixelSize)+2*padding);
vector<sf::RectangleShape> grid(WIDTH*HEIGHT);
vector<sf::RectangleShape> copy(WIDTH*HEIGHT);
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
    sf::RenderWindow app(sf::VideoMode(res.x, res.y), "Conway's Game of Life");
    init();
    app.setFramerateLimit(fps);
    float delay = 0;
    float cooldown = 0.5;
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
        for(auto& rect: grid)
        {
            app.draw(rect);
        }
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
    Color color = grid[cell].getFillColor();
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
                grid[cell].setFillColor(Color::White);
                copy[cell].setFillColor(Color::White);
            }
            else
            {
                grid[cell].setFillColor(Color::Black);
                copy[cell].setFillColor(Color::Black);
            }
            // set coordinates
            grid[cell].setPosition((col*pixelSize)+padding, (row*pixelSize)+padding);
            grid[cell].setSize(Vector2f(pixelSize, pixelSize));
            copy[cell].setPosition((col*pixelSize)+padding, (row*pixelSize)+padding);
            copy[cell].setSize(Vector2f(pixelSize, pixelSize));
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
            
            if(checkCell(i, j))
            {
                totalNeighbours += 1;
            }
        }
    }
    totalNeighbours -= checkCell(row, col);
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
                    copy[cell].setFillColor(Color::Red);
                }
                else
                {
                    copy[cell].setFillColor(Color::White);
                }
            }
            else
            {
                // dead and lives
                if(totalNeighbours == 3)
                {
                    copy[cell].setFillColor(Color::Green);
                }
                else
                {
                    copy[cell].setFillColor(Color::Black);
                }
            }
        }
    }
    // swap references
    vector<sf::RectangleShape>& temp = grid;
    grid = copy;
    copy = temp;
}