#include "ECS.h"

void ECS::update() {
	for (auto& e : _entities) {
		e->update();
	}
}

void ECS::draw() {
	for (auto& e : _entities) {
		e->draw();
	}
}

void ECS::refresh() {
	_entities.erase(std::remove_if(_entities.begin(), _entities.end(), [](const std::unique_ptr<Entity>& m) {
		return m->_destroyFlag;
	}), _entities.end());
}



Entity & ECS::addEntity(Entity * entity) {
	std::unique_ptr<Entity> ptr{ entity };
	_entities.emplace_back(std::move(ptr));
	return *entity;
}
