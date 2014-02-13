#include "Sprite.h"

Sprite::Sprite(SDL_Renderer *passedRenderer, std::string dest, int prior, int x, int y, int width, int height)
{
	renderer = passedRenderer;
	destinationOfImage = dest;
	priority = prior;
	spriteTexture = IMG_LoadTexture(renderer, destinationOfImage.c_str());
	mainRect.x = x;
	mainRect.y = y;
	mainRect.w = width;
	mainRect.h = height;
}

Sprite::Sprite(SDL_Renderer *passedRenderer, std::string dest, int prior, SDL_Rect rect)
{
	renderer = passedRenderer;
	destinationOfImage = dest;
	priority = prior;
	spriteTexture = IMG_LoadTexture(renderer, destinationOfImage.c_str());
	mainRect.x = rect.x;
	mainRect.y = rect.y;
	mainRect.w = rect.w;
	mainRect.h = rect.h;
}