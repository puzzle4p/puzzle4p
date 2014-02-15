#include "Sprite.h"
#include <iostream>

std::map<std::string, SDL_Texture *> Sprite::textureMap;

Sprite::Sprite(SDL_Renderer *passedRenderer, std::string dest, int prior, int x, int y, int width, int height)
{
	renderer = passedRenderer;
	destinationOfImage = dest;
	priority = prior;
	mainRect.x = x;
	mainRect.y = y;
	mainRect.w = width;
	mainRect.h = height;

	addTextureToMap(destinationOfImage, spriteTexture);
}

Sprite::Sprite(SDL_Renderer *passedRenderer, std::string dest, int prior, SDL_Rect rect)
{
	renderer = passedRenderer;
	destinationOfImage = dest;
	priority = prior;
	mainRect.x = rect.x;
	mainRect.y = rect.y;
	mainRect.w = rect.w;
	mainRect.h = rect.h;

	addTextureToMap(destinationOfImage, spriteTexture);
}

void Sprite::addTextureToMap(std::string destinationOfImage, SDL_Texture *spriteTexture)
{
	if (textureMap.find(destinationOfImage) == textureMap.end())
	{
		std::cout << "Zaladowano teksture: " << destinationOfImage << std::endl;
		spriteTexture = IMG_LoadTexture(renderer, destinationOfImage.c_str());
		textureMap[destinationOfImage] = spriteTexture;
	}
}