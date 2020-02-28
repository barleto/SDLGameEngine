#pragma once
#include <iostream>
#include <memory>
#include <map>
#include "component.h"

class Entity {
public:
	const char * name;
	void update();

	void draw();

	bool isActive();

	void setActive(bool active);

	void Destroy();

	bool destroyFlag = false;

	template<typename T>
	bool hasComponent() {
		return _componentsMap.find(getComponentTypeId<T>()) != _componentsMap.end();
	}

	template<typename T>
	T * addComponent() {
		try
		{
			T* component{ new T };
			component->entity = this;
			_componentsMap[getComponentTypeId<T>()] = component;
			component->start();
			return component;
		}
		catch (void *)
		{
			std::cout << "Error creating component." << std::endl;
			return nullptr;
		}
	}

	template<typename T>
	T * getComponent() {
		if (hasComponent<T>()) {
			return static_cast<T*>(_componentsMap[getComponentTypeId<T>()]);
		}
		return nullptr;
	}
protected:
	//Entity() {};
private:
	bool _active = true;
	std::map<ComponentId, Component*> _componentsMap;
};

