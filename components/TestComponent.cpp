#include "TestComponent.h"
#include "ECS/builtin/RigidBody.h"
#include <functional>


void TestComponent::start() {
	_initialPos = entity->transform().position();
	_rigidbody = entity->getComponent<RigidBody>();
	auto cc = entity->getComponent<ColliderComponent>();
}


void TestComponent::update() {
	if (!_rigidbody) {
		_rigidbody = entity->getComponent<RigidBody>();
		return;
	}

	if (InputManager::getKeyHoldDown(SDLK_w)) {
		_rigidbody->velocity.y -= 60 * GameEngine::deltaTime;
	}
	if (InputManager::getKeyHoldDown(SDLK_s)) {
		_rigidbody->velocity.y += 60 * GameEngine::deltaTime;
	}
	if (InputManager::getKeyHoldDown(SDLK_a)) {
		_rigidbody->velocity.x -= 60 * GameEngine::deltaTime;
	}
	if (InputManager::getKeyHoldDown(SDLK_d)) {
		_rigidbody->velocity.x += 60 * GameEngine::deltaTime;
	}
	if (InputManager::getKeyHoldDown(SDLK_q)) {
		entity->transform().rotation -= 300 * GameEngine::deltaTime;
	}
	if (InputManager::getKeyHoldDown(SDLK_e)) {
		entity->transform().rotation += 300 * GameEngine::deltaTime;
	}
	if (InputManager::getKeyHoldDown(SDLK_SPACE)) {
		entity->transform().rotation = 0;
		entity->transform().setPosition(_initialPos);
		_rigidbody->velocity.set(0, 0);
	}

	if (entity->transform().position().y > 630) {
		entity->transform().position().y = -30;
	}

	if (entity->transform().position().y < -30) {
		entity->transform().position().y = 630;
	}

	if (entity->transform().position().x > 840) {
		entity->transform().position().x = -40;
	}

	if (entity->transform().position().x < -40) {
		entity->transform().position().x = 840;
	}

	using namespace std;
	//cout << _rigidbody->velocity.x << endl;
}

void TestComponent::onCollision(GameObject * go) {
	using namespace std;
	cout << go->name << endl;
}
