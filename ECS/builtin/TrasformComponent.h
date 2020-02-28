#pragma once
#include "../component.h"
#include "vec2.h"

class TransformComponent: public Component
{
public:
	vec2i& position();
	void setPosition(int x, int y);
	float rotation;
	vec2f scale = vec2f(1,1);

private:
	vec2i _position;
};