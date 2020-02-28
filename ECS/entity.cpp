#include "entity.h"

void Entity::update() {
	for (auto& c : _componentsMap) {
		if (_active) {
			c.second->update();
		}
	}
}


void Entity::draw() {
	for (auto& c : _componentsMap) {
		if (_active) {
			c.second->draw();
		}
	}
}

bool Entity::isActive() { return _active; }

void Entity::setActive(bool active) { _active = active; }

void Entity::destroy() { destroyFlag = true; }

TransformComponent& Entity::transform()
{
	return *getComponent<TransformComponent>();
}

