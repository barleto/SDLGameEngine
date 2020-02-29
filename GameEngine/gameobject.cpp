#include "gameobject.h"

GameObject::GameObject(const char * name) {
	this->name = name;
	addComponent<TransformComponent>();
	GameEngine::ecs->addEntity(this);
}
