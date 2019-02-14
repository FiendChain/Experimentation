#include "App/App.hpp"
#include <SFML/Graphics.hpp>

int main(int argc, char *argv[])
{
    sf::Vector2f resolution(1920, 1080);

    app::App game(resolution.x, resolution.y, 60, "App");
    game.Run();
    
    return 0;
}
