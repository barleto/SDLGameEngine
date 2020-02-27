#pragma once
#include <iostream>

class Entity;

using ComponentId = std::size_t;

ComponentId getUniqueId();

template <typename T> ComponentId getComponentTypeId() {
	static ComponentId uid = getUniqueId();
	return uid;
}

class Component {
public:
	Entity* entity;
	virtual void start();
	virtual void update();
	virtual void draw();

	virtual ~Component();
};