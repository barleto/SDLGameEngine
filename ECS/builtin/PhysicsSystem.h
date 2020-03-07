#pragma once
#include <iostream>
#include "../system.h"
#include "../entity.h"
#include "TrasformComponent.h"

class PhyscisSystem : public System {
	void update() override {
		for (Entity* e : _entities) {
			e->getComponent<TransformComponent>()->position().y += 1;
		}
	}
};