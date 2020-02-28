#include "GameEngine.h"
#include "ECS/builtin/SpriteComponent.h"
#include "ECS/builtin/TrasformComponent.h"

GameEngine::GameEngine()
{}

GameEngine::~GameEngine()
{}

bool GameEngine::_isRunning;

SDL_Renderer* GameEngine::renderer = nullptr;

void GameEngine::init(const char title[], int xPos, int yPos, int width, int height,int targetFps , bool fullsreen)
{
	std::cout << "Initializing engine..." << std::endl;
	_targetFrameDelay = 1000/targetFps;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems initialized." << std::endl;
		GameEngine::_isRunning = true;
		int noFlags = 0;

		_window = SDL_CreateWindow(title, xPos, yPos, width, height, fullsreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : noFlags);
		if (!_window) {
			setFatalError("Unable to create Window: ");
		}
		renderer = SDL_CreateRenderer(_window, -1, 0);
		if(!renderer) {
			setFatalError("Unable to create renderer.");
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		_ecs = new ECS();
		Entity& e1 = _ecs->createEntity();
		e1.addComponent<SpriteComponent, const char*>("Assets/player.png");
	}
	else {
		setFatalError("Unable to start engine.");
	}
	

}

void GameEngine::loop()
{
	Uint32 frameStart;
	int frameTime;

	while (isRunning()) {
		frameStart = SDL_GetTicks();

		updatePhysics();
		handleInputs();
		updateLogic();
		render();
		_ecs->refresh();

		//wait if needed for frame time
		frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < _targetFrameDelay) {
			SDL_Delay(_targetFrameDelay - frameTime);
		}
	}
}

void GameEngine::handleInputs()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		GameEngine::_isRunning = false;
		break;
	default:
		break;
	}
}

void GameEngine::updatePhysics()
{
}

void GameEngine::updateLogic()
{
	_ecs->update();
}

void GameEngine::render()
{
	SDL_RenderClear(renderer);
	_ecs->draw();
	SDL_RenderPresent(renderer);
}

void GameEngine::clean()
{
	std::cout << "Quitting engine..." << std::endl;
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Closed." << std::endl;
}

void GameEngine::setFatalError(const char message[])
{
	GameEngine::_isRunning = false;
	std::cout << message<<":"<< SDL_GetError()<< std::endl;
}