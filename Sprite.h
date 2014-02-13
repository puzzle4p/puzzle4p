#ifndef SPRITE_H
#define SPRITE_H

#include "SDL.h"
#include <string>
#include "SDL_image.h"

class Sprite
{
public:
	Sprite(SDL_Renderer *passedRenderer, std::string dest, int prior, int x, int y, int width, int height);
	Sprite(SDL_Renderer *passedRenderer, std::string dest, int prior, SDL_Rect rect);
	int priority;
	std::string destinationOfImage;
	SDL_Texture *spriteTexture;
	SDL_Rect mainRect;
private:
	SDL_Renderer *renderer;
};

#endif // SPRITE_H
