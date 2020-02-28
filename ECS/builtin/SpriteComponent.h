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

	void start() override {
		_transform = entity->getComponent<TransformComponent>();
		_texture = TextureManager::loadTexture("Assets/player.png");
		_srcRect.x = _srcRect.y = 0;
		_srcRect.h = _srcRect.w = 32;
	}

	void update() override {
		_transform->position().x++;
		_transform->position().y++;
	}

	void draw() override {
		_destRect.x = _transform->position().x;
		_destRect.y = _transform->position().y;
		_destRect.w = _transform->scale.x * _srcRect.w;
		_destRect.h = _transform->scale.y * _srcRect.h;
		SDL_RenderCopy(Game::renderer, _texture, &_srcRect, &_destRect);
	}

private:
	SDL_Texture * _texture;
	SDL_Rect _srcRect;
	SDL_Rect _destRect;
	TransformComponent * _transform;
};