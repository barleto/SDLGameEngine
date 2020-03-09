#pragma once
#include <iostream>
#include "ECS/component.h"
#include "ECS/ECS.h"
#include "utils/vec2.h"
#include "ECS/builtin/PhysicsSystem.h"
#include "GameEngine.h"

class RigidBody : public Component {
public:
	float gravityScale = 1;
	vec2f velocity;
	bool useGravity = true;
	float friction = 0.4f;

	void start() override;

	~RigidBody();
};