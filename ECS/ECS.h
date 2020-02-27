#pragma once
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <memory>
#include <map>
#include "component.h"

class Entity {
public:
	void update() {
		for (auto& c : _componentsMap) {
			if (_active) {
				c.second->update();
			}
		}
	}

	void draw() {
		for (auto& c : _componentsMap) {
			if (_active) {
				c.second->draw();
			}
		}
	}

	bool isActive() { return _active; }

	void setActive(bool active) { _active = active; }

	void Destroy() { destroyFlag = true; }

	bool destroyFlag = false;

	template<typename T>
	bool hasComponent() {
		return _componentsMap.find(getComponentTypeId<T>()) != _componentsMap.end();
	}

	template<typename T>
	T & addComponent() {
		try
		{
			T* component{ new T };
			component->entity = this;
			std::unique_ptr<Component> ptr{ component };
			_componentsMap[getComponentTypeId<T>()] = std::move(ptr);
			component->start();
			return *component;
		}
		catch (void *)
		{
			std::cout << "Error creating component." << std::endl;
		}
	}

	template<typename T>
	T & getComponent() {
		if (hasComponent<T>()) {
			return _componentsMap[getComponentTypeId<T>()];
		}
		return nullptr;
	}

private:
	bool _active = true;
	std::map<ComponentId, std::unique_ptr<Component>> _componentsMap;
};

class TransformComponent : public Component
{
public:
	void start() override {
		std::cout << "CRIADOOOO" << std::endl;
	}

	void update() override {
		std::cout << "Alalaoooo" << std::endl;
	}

	void draw() override {
		std::cout << "desenhando" << std::endl;
	}
};

class ECS
{
public:
	void update() {
		for (auto& e : _entities) {
			e->update();
		}
	}
	void draw() {
		for (auto& e : _entities) {
			e->draw();
		}
	}

	void refresh() {
		_entities.erase(std::remove_if(_entities.begin(), _entities.end(), [](const std::unique_ptr<Entity>& m) {
			return m->destroyFlag;
		}), _entities.end());
	}

	Entity& createEntity() {
		Entity* entity = new Entity();
		entity->addComponent<TransformComponent>();
		std::unique_ptr<Entity> ptr{entity};
		_entities.emplace_back(std::move(ptr));
		return *entity;
	}

private:
	std::vector<std::unique_ptr<Entity>> _entities;
};

