#pragma once
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <memory>
#include <map>
#include "entity.h"
#include "builtin/TrasformComponent.h"

class ECS
{
public:
	void update();
	void draw();
	void refresh();
	Entity& addEntity(Entity * entity);

private:
	std::vector<std::unique_ptr<Entity>> _entities;
};

