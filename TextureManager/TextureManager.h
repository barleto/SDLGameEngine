#pragma once
#include "GameEngine.h"
#include "SDL_image.h"
#include <memory>

class SDL_TextureInfo {
public:
	Uint32 format;
	int access, width, height;
};

class TextureManager
{
public:
	static SDL_Texture * loadTexture(const char filenName[]);
	static std::unique_ptr<SDL_TextureInfo> getTextureInfo(SDL_Texture* texture);
};


