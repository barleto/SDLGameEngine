#pragma once
#include "../component.h"
#include "vec2.h"

class TransformComponent: public Component
{
public:
	vec2f& position();
	void setPosition(float x, float y);
	void setPosition(vec2f vec);
	double rotation;
	vec2f scale = vec2f(1,1);

private:
	vec2f _position;
};