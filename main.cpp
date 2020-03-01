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
	auto sc = go->addComponent(new SpriteComponent("Assets/title.png"));
	auto& windowSize = GameEngine::windowSize;
	auto sSize = sc->getSize();
	go->transform().setPosition(windowSize.x/2 - sSize.x/2, windowSize.y/2 - sSize.y/2);
	go->addComponent(new TestComponent());
}