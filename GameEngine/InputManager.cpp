#include "InputManager.h"

bool InputManager::getKeyUp(SDL_Keycode keyCode)
{
	auto event = GameEngine::currentEvent;
	if (event.type != SDL_KEYUP) return false;
	if (event.key.keysym.sym != keyCode) return false;
	auto statePair = _keyState[keyCode];
	return statePair.first != statePair.second;
}

bool InputManager::getKeyDown(SDL_Keycode keyCode)
{
	auto event = GameEngine::currentEvent;
	if (event.type != SDL_KEYDOWN) return false;
	if (event.key.keysym.sym != keyCode) return false;
	auto statePair = _keyState[keyCode];
	return statePair.first != statePair.second;
}

bool InputManager::getKeyHoldDown(SDL_Keycode keyCode)
{
	if (_keyState.find(keyCode) != _keyState.end() ) {
		auto statePair = _keyState[keyCode];
		return statePair.second;
	}

	return false;
}

void InputManager::updateKeyState(SDL_EventType keyboardEventType ,SDL_Keycode keyCode)
{
	auto& statePair = _keyState[keyCode];
	statePair.first = statePair.second;
	statePair.second = keyboardEventType == SDL_KEYDOWN;
}

std::map<SDL_Keycode, std::pair<bool,bool>> InputManager::_keyState;
