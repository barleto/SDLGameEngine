#pragma once
#include "GameEngine.h"
#include <map>

class InputManager {
public:
	static bool getKeyUp(SDL_Keycode keyCode);
	static bool getKeyDown(SDL_Keycode keyCode);
	static bool getKeyHoldDown(SDL_Keycode keyCode);
	static void updateKeyState(SDL_EventType keyboardEventType, SDL_Keycode keyCode);

private:
	static std::map<SDL_Keycode, std::pair<bool,bool>> _keyState;
};