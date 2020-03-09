#include "Collision.h"

bool Collision::AABB(const SDL_Rect & rectA, const SDL_Rect & rectB)
{
	return rectA.x + rectA.w >= rectB.x
		&& rectB.x + rectB.w >= rectA.x
		&& rectA.y + rectA.h >= rectB.y
		&& rectB.y + rectB.h >= rectA.y;
}

bool Collision::AABB(ColliderComponent & colA, ColliderComponent & colB)
{
	auto positionA = colA.entity->transform().position();
	auto positionB = colB.entity->transform().position();
	auto rectA = colA.getRect();
	rectA.x = static_cast<int>(positionA.x);
	rectA.y = static_cast<int>(positionA.y);
	auto rectB = colB.getRect();
	rectB.x = static_cast<int>(positionB.x);
	rectB.y = static_cast<int>(positionB.y);
	return AABB(rectA, rectB);
}
