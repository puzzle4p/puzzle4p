#ifndef SPRITE_H
#define SPRITE_H

#include "SDL.h"
#include <string>

class Sprite
{
public:
	Sprite(std::string dest, int prior, int x, int y, int width, int height);
	Sprite(std::string dest, int prior, SDL_Rect rect);
	int priority;
	std::string destinationOfImage;
	SDL_Surface *spriteSurface;
	SDL_Rect mainRect;
};

#endif // SPRITE_H
