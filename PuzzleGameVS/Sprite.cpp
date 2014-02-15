#include "Sprite.h"
#include <iostream>

std::map<std::string, SDL_Texture *> Sprite::textureMap;

Sprite::Sprite(SDL_Renderer *passedRenderer, std::string dest, int prior, int x, int y, int width, int height, global_States spriteState)
{
	renderer = passedRenderer;
	destinationOfImage = dest;
	priority = prior;
	state = spriteState;
	mainRect.x = x;
	mainRect.y = y;
	mainRect.w = width;
	mainRect.h = height;

	addTextureToMap();
}

Sprite::Sprite(SDL_Renderer *passedRenderer, std::string dest, int prior, SDL_Rect rect, global_States spriteState)
{
	renderer = passedRenderer;
	destinationOfImage = dest;
	priority = prior;
	state = spriteState;
	mainRect.x = rect.x;
	mainRect.y = rect.y;
	mainRect.w = rect.w;
	mainRect.h = rect.h;

	addTextureToMap();
}

void Sprite::addTextureToMap()
{
	if (textureMap.find(destinationOfImage) == textureMap.end())
	{
		std::cout << "Zaladowano teksture: " << destinationOfImage << std::endl;
		spriteTexture = IMG_LoadTexture(renderer, destinationOfImage.c_str());
		textureMap[destinationOfImage] = spriteTexture;
	}
	else
	{
		std::cout << "Tekstura ju¿ istnieje, przypisuje: " << textureMap[destinationOfImage] << std::endl;
		spriteTexture = textureMap[destinationOfImage];
	}
}