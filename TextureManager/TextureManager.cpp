#include "TextureManager.h"

SDL_Texture* TextureManager::loadTexture(const char filenName[])
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(filenName);
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", filenName, IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(GameEngine::renderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", filenName, SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}

std::unique_ptr<SDL_TextureInfo> TextureManager::getTextureInfo(SDL_Texture * texture)
{
	std::unique_ptr<SDL_TextureInfo> ptr{ new SDL_TextureInfo() };
	if (SDL_QueryTexture(texture, &ptr->format, &ptr->access, &ptr->width, &ptr->height))
	{
		GameEngine::setFatalError("Unable to get info ont Texture.");
	}
	return ptr;
}
