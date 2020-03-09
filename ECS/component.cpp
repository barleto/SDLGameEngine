#include "component.h"

ComponentId getUniqueId() {
	static ComponentId idCounter = 0;
	return idCounter++;
}

void Component::start() {}

void Component::update() {}

void Component::draw() {}

void Component::onCollision(GameObject * go) {}

Component::~Component() {}
