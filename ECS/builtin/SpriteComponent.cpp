#include "SpriteComponent.h"

SpriteComponent::SpriteComponent(const char * path) : SpriteComponent(path, 0, 0) {
	auto info = TextureManager::getTextureInfo(_texture);
	_width = info->width;
	_height = info->height;
}

SpriteComponent::SpriteComponent(const char * path, int width, int height) {
	_texture = TextureManager::loadTexture(path);
	_width = width;
	_height = height;
}

void SpriteComponent::start() {
	_srcRect.x = _srcRect.y = 0;
	_srcRect.h = _height;
	_srcRect.w = _width;
}

void SpriteComponent::draw() {
	auto transform = entity->transform();
	_destRect.x = static_cast<int>(transform.position().x);
	_destRect.y = static_cast<int>(transform.position().y);
	_destRect.w = static_cast<int>(abs(transform.scale.x) * _srcRect.w);
	_destRect.h = static_cast<int>(abs(transform.scale.y) * _srcRect.h);
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	flip = SDL_RendererFlip(flip | SDL_RendererFlip(transform.scale.y < 0 ? SDL_FLIP_VERTICAL : SDL_FLIP_NONE));
	flip = SDL_RendererFlip(flip | SDL_RendererFlip(transform.scale.x < 0 ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE));
	SDL_RenderCopyEx(GameEngine::renderer, _texture, &_srcRect, &_destRect, transform.rotation, nullptr, flip);
}

SpriteComponent::~SpriteComponent() {
	SDL_DestroyTexture(_texture);
}

vec2i SpriteComponent::getSize()
{
	return vec2i(_width, _height);
}
