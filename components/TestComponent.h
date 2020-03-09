#pragma once
#include "imports.h"
#include "ECS/builtin/RigidBody.h"
#include "ECS/builtin/ColliderComponent.h"

class TestComponent : public Component {
public:

	void start() override;
	void update() override;

private:
	vec2f _initialPos;
	RigidBody* _rigidbody;
};