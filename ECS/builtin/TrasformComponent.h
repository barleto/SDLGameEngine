#pragma once
#include "../component.h"
#include "vec2.h"
#include <vector>

class TransformComponent: public Component
{
public:
	vec2f position();
	vec2f localPosition();
	void updateGlobalPosition();
	void updateLocalPosition();
	void setPosition(float x, float y);
	void setLocalPosition(float x, float y);
	void setParent(TransformComponent * parent, bool stayGlobalPosition);

private:
	vec2f lPos;
	vec2f gPos;
	TransformComponent * parent = nullptr;
	std::vector<TransformComponent> child;
};