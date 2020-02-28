#include "gameobject.h"

GameObject::GameObject()
{
	addComponent<TransformComponent>();
	GameEngine::ecs->addEntity(this);
}
