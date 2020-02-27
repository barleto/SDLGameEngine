#pragma once
#include "../component.h"
#include "../../utils/vec2.h"
#include <vector>

class TransformComponent : public Component
{
public:

	void update() override {}

private:
	vec2i position;
	TransformComponent * parent;
	std::vector<TransformComponent> child;
};