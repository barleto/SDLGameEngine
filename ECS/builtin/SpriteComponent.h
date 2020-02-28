#pragma once
#include "../component.h"
#include "../entity.h"
#include "../../game.h"
#include "TrasformComponent.h"
#include "SDL.h"
#include "SDL_image.h"
#include "../../TextureManager/TextureManager.h"

class SpriteComponent : public Component {
public:
	SpriteComponent() = default;
	SpriteComponent(const char * path) {
		_texture = TextureManager::loadTexture(path);
	}


	void start() override {
		_transform = entity->getComponent<TransformComponent>();
		_srcRect.x = _srcRect.y = 0;
		_srcRect.h = _srcRect.w = 32;
	}

	void draw() override {
		_destRect.x = _transform->position().x;
		_destRect.y = _transform->position().y;
		_destRect.w = int(_transform->scale.x * _srcRect.w);
		_destRect.h = int(_transform->scale.y * _srcRect.h);
		SDL_RenderCopy(Game::renderer, _texture, &_srcRect, &_destRect);
	}

private:
	SDL_Texture * _texture;
	SDL_Rect _srcRect;
	SDL_Rect _destRect;
	TransformComponent * _transform;
};