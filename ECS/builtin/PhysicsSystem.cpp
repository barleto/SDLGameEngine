#include "PhysicsSystem.h"

void PhyscisSystem::update() {
	for (Entity* e : _entities) {
		auto rigidbody = e->getComponent<RigidBody>();
		if (rigidbody) {
			auto transform = e->getComponent<TransformComponent>();
			if (rigidbody->useGravity) {
				rigidbody->velocity.y -= gravity;
			}
			transform->position() += rigidbody->velocity;
			rigidbody->velocity.truncate((1-rigidbody->friction) * rigidbody->velocity.length());
		}
	}
}
