#include "GameEngine.h"
#include "ECS/builtin/SpriteComponent.h"
#include "ECS/builtin/TrasformComponent.h"

GameEngine::GameEngine()
{}

GameEngine::~GameEngine()
{}

bool GameEngine::_isRunning;

SDL_Renderer* GameEngine::renderer = nullptr;
ECS* GameEngine::ecs = nullptr;
SDL_Event GameEngine::currentEvent;
vec2f GameEngine::windowSize;
float GameEngine::deltaTime = 0;

void GameEngine::init(const char title[], int xPos, int yPos, int width, int height,int targetFps , bool fullsreen)
{
	std::cout << "Initializing engine..." << std::endl;
	_targetFrameDelay = 1000/targetFps;
	GameEngine::ecs = new ECS();
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems initialized." << std::endl;
		GameEngine::_isRunning = true;
		int noFlags = 0;

		_window = SDL_CreateWindow(title, xPos, yPos, width, height, fullsreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : noFlags);
		if (!_window) {
			setFatalError("Unable to create Window: ");
		}
		windowSize.set(static_cast<float>(width), static_cast<float>(height));
		renderer = SDL_CreateRenderer(_window, -1, 0);
		if(!renderer) {
			setFatalError("Unable to create renderer.");
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		ecs->addSystem(new PhyscisSystem());
	}
	else {
		setFatalError("Unable to start engine.");
	}
	

}

void GameEngine::loop()
{
	Uint32 frameStart;
	int frameTime;
	float lastUpdateLogicTime = 0;
	float lastUpdateSystemsTime = 0;

	while (isRunning()) {
		frameStart = SDL_GetTicks();

		deltaTime = (SDL_GetTicks() - lastUpdateSystemsTime) / 1000;
		updatePhysics();
		lastUpdateSystemsTime = static_cast<float>(SDL_GetTicks());

		handleInputs();

		deltaTime = (SDL_GetTicks() - lastUpdateLogicTime) / 1000;
		updateLogic();
		lastUpdateLogicTime = static_cast<float>(SDL_GetTicks());

		render();

		ecs->refresh();

		//wait if needed for frame time
		frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < _targetFrameDelay) {
			SDL_Delay(_targetFrameDelay - frameTime);
		}
	}
}

void GameEngine::handleInputs()
{
	SDL_PollEvent(&currentEvent);
	switch (currentEvent.type)
	{
	case SDL_QUIT:
		GameEngine::_isRunning = false;
		break;
	case SDL_KEYDOWN:
	case SDL_KEYUP:
		InputManager::updateKeyState((SDL_EventType)currentEvent.type, currentEvent.key.keysym.sym);
		break;
	default:
		break;
	}
}

void GameEngine::updatePhysics()
{
	ecs->updateSystems();
}

void GameEngine::updateLogic()
{
	ecs->updateLogic();
}

void GameEngine::render()
{
	SDL_RenderClear(renderer);
	ecs->draw();
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
