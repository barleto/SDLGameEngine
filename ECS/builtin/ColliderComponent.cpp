#include "ColliderComponent.h"

ColliderComponent::ColliderComponent(bool isTrigger) {
	this->isTrigger = isTrigger;
}

void ColliderComponent::start() {
	tryToGetSpriteComponent();
}

void ColliderComponent::copyRectFromSprite() {
	tryToGetSpriteComponent();
}

void ColliderComponent::draw() {
	if (debug && _spriteRef) {
		auto position = entity->transform().position();
		Uint8 r, g, b, a;
		SDL_GetRenderDrawColor(GameEngine::renderer, &r, &g, &b, &a);
		SDL_SetRenderDrawColor(GameEngine::renderer, 255, 0, 0, 255);
		SDL_Point points[5] = {
			{ static_cast<int>(position.x), static_cast<int>(position.y) },
			{ static_cast<int>(position.x + _rect.w), static_cast<int>(position.y) },
			{ static_cast<int>(position.x + _rect.w), static_cast<int>(position.y + _rect.h) },
			{ static_cast<int>(position.x), static_cast<int>(position.y + _rect.h) },
			{ static_cast<int>(position.x), static_cast<int>(position.y) }
		};
		SDL_RenderDrawLines(GameEngine::renderer, points, 5);
		SDL_SetRenderDrawColor(GameEngine::renderer, r, g, b, a);
	}
}

const SDL_Rect ColliderComponent::getRect() {
	return _rect;
}

void ColliderComponent::tryToGetSpriteComponent() {
	if (!_spriteRef) {
		_spriteRef = entity->getComponent<SpriteComponent>();
		if (_spriteRef) {
			auto size = _spriteRef->getSize();
			auto transform = entity->transform();
			_rect.w = size.x;
			_rect.h = size.y;
		}
	}
}
