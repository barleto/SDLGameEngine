#pragma once
#include "../component.h"
#include "../entity.h"
#include "TrasformComponent.h"
#include "SDL.h"
#include "SDL_image.h"

class SpriteComponent : public Component {
public:
	SpriteComponent() = default;
	SpriteComponent(const char* path) {
		_transform = &(entity->getComponent<TransformComponent>());
	}

	void start() override {
		srcRect.x = srcRect.y = 0;
		srcRect.h = srcRect.w = 32;
	}

	void draw() override {
		destRect.x = _transform->position().x;
		destRect.y = _transform->position().y;
		destRect.w = _transform->scale.x * srcRect.w;
		destRect.h = _transform->scale.y * srcRect.h;
	}

private:
	SDL_Texture * texture;
	SDL_Rect srcRect;
	SDL_Rect destRect;
	TransformComponent * _transform;
};