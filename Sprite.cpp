#include "Sprite.h"

Sprite::Sprite(std::string dest, int prior, int x, int y, int width, int height)
{
	destinationOfImage = dest;
	priority = prior;
	spriteSurface = SDL_LoadBMP(destinationOfImage.c_str());
	mainRect.x = x;
	mainRect.y = y;
	mainRect.w = width;
	mainRect.h = height;
}

Sprite::Sprite(std::string dest, int prior, SDL_Rect rect)
{
	destinationOfImage = dest;
	priority = prior;
	spriteSurface = SDL_LoadBMP(destinationOfImage.c_str());
	mainRect.x = rect.x;
	mainRect.y = rect.y;
	mainRect.w = rect.w;
	mainRect.h = rect.h;
}