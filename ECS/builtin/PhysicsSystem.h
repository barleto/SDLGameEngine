#pragma once
#include <iostream>
#include "../system.h"
#include "../entity.h"
#include "TrasformComponent.h"
#include "RigidBody.h"

class PhyscisSystem : public System {
public:
	float gravity = -0.2f;
	void update() override;
};