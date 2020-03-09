#pragma once
#include <iostream>
#include <vector>
#include "imports.h"

class ColliderComponent;

class ColliderComponent : public Component{
public:
	ColliderComponent(bool isTrigger);
	void start() override;
	void copyRectFromSprite();
	void draw();
	const SDL_Rect getRect();

	bool debug = false;
	bool isTrigger;
	
private:
	SDL_Rect _rect;
	SpriteComponent * _spriteRef;
	void tryToGetSpriteComponent();
};
