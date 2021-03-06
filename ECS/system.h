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
	virtual void update() = 0;
	virtual void subscribeEntity(Entity* e);
	virtual void unsubscribeEntity(Entity* e);

protected:
	std::set<Entity*> _entities;
};