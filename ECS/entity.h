#pragma once
#include <iostream>
#include <memory>
#include <map>
#include "component.h"
#include "builtin/TrasformComponent.h"
#include "ECS.h"

class Entity {
public:
	friend class ECS;

	void update();

	void draw();

	bool isActive();

	void setActive(bool active);

	void destroy();

	TransformComponent& transform();

	template<typename T>
	bool hasComponent() {
		return _componentsMap.find(getComponentTypeId<T>()) != _componentsMap.end();
	}

	template<typename T, typename... TArgs>
	T * addComponent(TArgs... args) {
		try
		{
			T* component{ new T(args...) };
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
	T * addComponent(T* component) {
		try
		{
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
	Entity() {};
private:
	bool _destroyFlag = false;
	bool _active = true;
	std::map<ComponentId, Component*> _componentsMap;
};

