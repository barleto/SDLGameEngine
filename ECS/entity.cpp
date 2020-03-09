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

void Entity::destroy() { 
	_destroyFlag = true;
	setActive(false);
}

std::vector<Component*> Entity::getComponentsList() {
	auto v = std::vector<Component*>();
	for (auto it = _componentsMap.begin(); it != _componentsMap.end(); ++it) {
		v.push_back(it->second);
	}
	return v;
}

TransformComponent& Entity::transform()
{
	return *getComponent<TransformComponent>();
}

