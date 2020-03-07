#pragma once
#include <iostream>
#include <set>

class Entity;

using SystemId = std::size_t;

SystemId getUniqueSysId();

template <typename T> SystemId getSystemTypeId() {
	static SystemId uid = getUniqueSysId();
	return uid;
}

class System {
public:
	SystemId id = getUniqueSysId();
	virtual void update() = 0;
	void subscribeEntity(Entity* e);
	void unsubscribeEntity(Entity* e);

protected:
	std::set<Entity*> _entities;
};