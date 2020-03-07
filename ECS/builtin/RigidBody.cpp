#include "RigidBody.h"

void RigidBody::start() {
	GameEngine::ecs->registerEntityToSystem<PhyscisSystem>(this->entity);
}

RigidBody::~RigidBody() {
	GameEngine::ecs->unregisterEntityToSystem<PhyscisSystem>(this->entity);
}
