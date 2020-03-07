#include "TrasformComponent.h"

vec2f& TransformComponent::position()
{
	return _position;
}

void TransformComponent::setPosition(float x, float y)
{
	_position.set(x, y);
}

void TransformComponent::setPosition(vec2f vec)
{
	setPosition(vec.x, vec.y);
}
