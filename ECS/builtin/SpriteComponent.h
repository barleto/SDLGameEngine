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

	void draw() override {
		auto transform = entity->transform();
		_destRect.x = transform.position().x;
		_destRect.y = transform.position().y;
		_destRect.w = int(transform.scale.x * _srcRect.w);
		_destRect.h = int(transform.scale.y * _srcRect.h);
		SDL_RenderCopy(Game::renderer, _texture, &_srcRect, &_destRect);
	}

	~SpriteComponent() {
		delete _texture;
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