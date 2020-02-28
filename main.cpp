#include <iostream>
#include "SDL.h"
#include "GameEngine.h"

int main(int argc, char *argv[]) {

	GameEngine * game = new GameEngine();

	game->init("SDLEngine",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800,600, 60, false);
	game->loop();
	game->clean();
	
	return 0;

}