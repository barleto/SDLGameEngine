#include "TrasformComponent.h"

vec2i& TransformComponent::position()
{
	return _position;
}

void TransformComponent::setPosition(int x, int y)
{
	_position.set(x, y);
}