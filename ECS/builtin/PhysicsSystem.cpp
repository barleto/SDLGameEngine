#include "PhysicsSystem.h"
#include "ECS/builtin/ColliderComponent.h"
#include "GameEngine/Collision.h"

void PhyscisSystem::update() {
	for (Entity* e : _entities) {
		//physics gravity and velocity
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

		//Collision
		auto collider = e->getComponent<ColliderComponent>();
		if (collider) {
			if (collider->isTrigger) {
				for (Entity* other: _entities) {
					if (e != other) {
						auto otherCollider = other->getComponent<ColliderComponent>();
						if (otherCollider && Collision::AABB(*collider, *otherCollider)) {
							for (auto c : e->getComponentsList()) {
								c->onCollision(static_cast<GameObject*>(other));
							}
							for (auto c : other->getComponentsList()) {
								c->onCollision(static_cast<GameObject*>(e));
							}
						}
					}
				}
			}
			else {
				//physics collision
				//get intrusion, then move objects as if they are not colliding anymore via the shortest axis they intersect
			}
		}
	}
}
