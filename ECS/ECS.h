#pragma once
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>
#include "entity.h"
#include "system.h"
#include "builtin/TrasformComponent.h"

class ECS
{
public:
	void updateSystems();
	void updateLogic();
	void draw();
	void refresh();
	Entity* addEntity(Entity * entity);

	template <typename T>
	void registerEntityToSystem(Entity * e) {
		if (_systems.find(getSystemTypeId<T>()) == _systems.end()) {
			return;
		}
		System* s = _systems[getSystemTypeId<T>()];
		s->subscribeEntity(e);
	}

	template <typename T>
	void unregisterEntityToSystem(Entity * e) {
		if (_systems.find(getSystemTypeId<T>()) == _systems.end()) {
			return;
		}
		System* s = _systems[getSystemTypeId<T>()];
		s->unsubscribeEntity(e);
	}

	template <class T>
	void addSystem(T * system)
	{
		_systems[getSystemTypeId<T>()] = system;
	}

private:
	std::vector<Entity*> _entities;
	std::map<SystemId, System*> _systems;
};

