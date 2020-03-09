#pragma once
#include <iostream>
#include "SDL.h"
#include "ECS/builtin/ColliderComponent.h"

class Collision {
public:
	static bool AABB(const SDL_Rect& rectA, const SDL_Rect& rectB);
	static bool AABB(ColliderComponent& colA, ColliderComponent& colB);
};