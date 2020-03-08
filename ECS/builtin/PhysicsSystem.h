#pragma once
#include <iostream>
#include <cmath>
#include "../system.h"
#include "../entity.h"
#include "TrasformComponent.h"
#include "RigidBody.h"

class PhyscisSystem : public System {
public:
	float gravity = -16.6666f;
	void update() override;
	vec2f unitSizeInPixels = vec2f(60,60);
};