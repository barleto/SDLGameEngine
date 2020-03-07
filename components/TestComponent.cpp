#include "TestComponent.h"
#include "ECS/builtin/RigidBody.h"
void TestComponent::start() {
	_initialPos = entity->transform().position();
	_rigidbody = entity->getComponent<RigidBody>();
}

void TestComponent::update() {
	if (!_rigidbody) {
		_rigidbody = entity->getComponent<RigidBody>();
		return;
	}
	if (InputManager::getKeyHoldDown(SDLK_w)) {
		_rigidbody->velocity.y -= 1;
	}
	if (InputManager::getKeyHoldDown(SDLK_s)) {
		_rigidbody->velocity.y += 1;
	}
	if (InputManager::getKeyHoldDown(SDLK_a)) {
		_rigidbody->velocity.x -= 1;
	}
	if (InputManager::getKeyHoldDown(SDLK_d)) {
		_rigidbody->velocity.x += 1;
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
		_rigidbody->velocity.set(0, 0);
	}
}
