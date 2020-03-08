#include "PhysicsSystem.h"

void PhyscisSystem::update() {
	for (Entity* e : _entities) {
		auto rigidbody = e->getComponent<RigidBody>();
		if (rigidbody) {
			auto transform = e->getComponent<TransformComponent>();
			if (rigidbody->useGravity) {
				rigidbody->velocity.y -= rigidbody->gravityScale * gravity * GameEngine::deltaTime;
			}
			auto velocityVector = rigidbody->velocity * unitSizeInPixels * GameEngine::deltaTime;
			transform->position() += velocityVector;

			if (rigidbody->friction > 0 && rigidbody->friction <= 1) {
				auto friction = std::pow(1 - rigidbody->friction, GameEngine::deltaTime);;
				rigidbody->velocity *= friction;
			}
	
		}
	}
}
