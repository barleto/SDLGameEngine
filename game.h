#pragma once
#include "SDL.h"
#include <memory>
#include <iostream>
#include "ECS/ECS.h"

class Game
{
public:
	Game();
	~Game();
	void init(const char title[], int xPos, int yPos, int width, int height, int targetFps, bool fullsreen);
	void loop();
	void clean();

	bool isRunning() { return _isRunning; }
	static SDL_Renderer * renderer;
	static void setFatalError(const char message[]);
private:

	void handleInputs();
	void updatePhysics();
	void updateLogic();
	void render();

	int _targetFrameDelay;
	SDL_Window * _window;
	ECS * _ecs;

	static bool _isRunning;
};

