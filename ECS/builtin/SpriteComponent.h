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
	SpriteComponent(const char * path);
	SpriteComponent(const char * path, int width, int height);

	void start() override;
	void update() override{}
	void draw() override;

	~SpriteComponent();

	void setWidth(int width) { _width = width; };
	void setHeight(int height) { _height = height; };
	vec2i getSize();

private:
	SDL_Texture * _texture;
	SDL_Rect _srcRect;
	SDL_Rect _destRect;
	int _width = 0;
	int _height = 0;
};