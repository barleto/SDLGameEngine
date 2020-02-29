#pragma once
#include "ECS/entity.h"
#include "GameEngine.h"
#include "ECS/builtin/TrasformComponent.h"

class GameObject : public Entity {
public:
	const char* name;
	GameObject(const char* name = "");
};