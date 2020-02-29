#include <iostream>
#include "GameEngine/imports.h"

void setupScene();

int main(int argc, char *argv[]) {

	GameEngine * game = new GameEngine();

	game->init("SDLEngine",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800,600, 60, false);
	setupScene();
	game->loop();
	game->clean();
	
	return 0;

}

void setupScene() {
	GameObject* go = new GameObject("player") ;
	go->addComponent(new SpriteComponent("Assets/player.png"));
}