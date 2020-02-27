#pragma once
#include "../component.h"
#include "vec2.h"

class TransformComponent: public Component
{
public:
	vec2i position();
	vec2i localPosition();
	void setPosition(float x, float y);
	void setLocalPosition(float x, float y);
	void setParent(TransformComponent * parent, bool stayGlobalPosition);
	Entity * parent();
	float rotation;
	vec2i scale;

private:
	vec2i _lPos;
	vec2i _gPos;
	void updateGlobalPosition();
	void updateLocalPosition();
	TransformComponent * _parent = nullptr;
};