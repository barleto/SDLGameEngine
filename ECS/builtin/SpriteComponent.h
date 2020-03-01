#pragma once
#include "../component.h"
#include "../entity.h"
#include "GameEngine.h"
#include "TrasformComponent.h"
#include "SDL.h"
#include "SDL_image.h"
#include "../../TextureManager/TextureManager.h"
#include <cmath>
#include "InputManager.h"

class SpriteComponent : public Component {
public:
	SpriteComponent() = default;
	SpriteComponent(const char * path): SpriteComponent(path, 0, 0) {
		auto info = TextureManager::getTextureInfo(_texture);
		_width = info->width;
		_height = info->height;
	}
	SpriteComponent(const char * path, int width, int height) {
		_texture = TextureManager::loadTexture(path);
		_width = width;
		_height = height;
	}

	void start() override {
		_srcRect.x = _srcRect.y = 0;
		_srcRect.h = _height; 
		_srcRect.w = _width;
	}

	void update() override{}

	void draw() override {
		auto transform = entity->transform();
		_destRect.x = transform.position().x;
		_destRect.y = transform.position().y;
		_destRect.w = int(abs(transform.scale.x) * _srcRect.w);
		_destRect.h = int(abs(transform.scale.y) * _srcRect.h);
		SDL_RendererFlip flip = SDL_FLIP_NONE;
		flip = SDL_RendererFlip(flip | SDL_RendererFlip(transform.scale.y < 0? SDL_FLIP_VERTICAL : SDL_FLIP_NONE));
		flip = SDL_RendererFlip(flip | SDL_RendererFlip(transform.scale.x < 0? SDL_FLIP_HORIZONTAL: SDL_FLIP_NONE));
		SDL_RenderCopyEx(GameEngine::renderer, _texture, &_srcRect, &_destRect, transform.rotation, nullptr, flip);
	}

	~SpriteComponent() {
		SDL_DestroyTexture(_texture);
	}

	void setWidth(int width) { _width = width; };
	void setHeight(int height) { _height = height; };

private:
	SDL_Texture * _texture;
	SDL_Rect _srcRect;
	SDL_Rect _destRect;
	int _width = 0;
	int _height = 0;
};