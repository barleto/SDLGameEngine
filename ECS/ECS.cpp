#include "ECS.h"

void ECS::updateSystems(){
	for (auto pair : _systems) {
		pair.second->update();
	}
}

void ECS::updateLogic() {
	for (auto e : _entities) {
		e->update();
	}
}

void ECS::draw() {
	for (auto e : _entities) {
		e->draw();
	}
}

void ECS::refresh() {
	_entities.erase(std::remove_if(_entities.begin(), _entities.end(), [](const Entity* m) {
		if (m->_destroyFlag) {
			delete m;
		}
		return m->_destroyFlag;
	}), _entities.end());
}



Entity * ECS::addEntity(Entity * entity) {
	_entities.emplace_back(entity);
	return entity;
}
