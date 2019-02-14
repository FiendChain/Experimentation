#include "Game/Game.hpp"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	Game game(120, 1600, 900);
	game.run();
	return EXIT_SUCCESS;
}