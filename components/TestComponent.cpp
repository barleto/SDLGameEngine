#include "TestComponent.h"
#include "ECS/ECS.h"
#include "GameEngine.h"
#include "ECS/builtin/PhysicsSystem.h"

void TestComponent::start() {
	_initialPos = entity->transform().position();
}

void TestComponent::update() {
	if (InputManager::getKeyHoldDown(SDLK_w)) {
		entity->transform().position().y -= 5;
	}
	if (InputManager::getKeyHoldDown(SDLK_s)) {
		entity->transform().position().y += 5;
	}
	if (InputManager::getKeyHoldDown(SDLK_a)) {
		entity->transform().position().x -= 5;
	}
	if (InputManager::getKeyHoldDown(SDLK_d)) {
		entity->transform().position().x += 5;
	}
	if (InputManager::getKeyHoldDown(SDLK_q)) {
		entity->transform().rotation -= 5;
	}
	if (InputManager::getKeyHoldDown(SDLK_e)) {
		entity->transform().rotation += 5;
	}
	if (InputManager::getKeyDown(SDLK_SPACE)) {
		entity->transform().rotation = 0;
		entity->transform().setPosition(_initialPos);
	}
}