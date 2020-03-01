#include <iostream>
#include "GameEngine/imports.h"
#include "components/TestComponent.h"

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
	GameObject* go = new GameObject("title");
	go->addComponent(new SpriteComponent("Assets/title.png"));
	go->transform().setPosition(400 - 40, 300 - 30);
	go->addComponent(new TestComponent());
}