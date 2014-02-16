#ifndef SPRITE_H
#define SPRITE_H

#include "SDL.h"
#include <string>
#include "SDL_image.h"
#include <map>
#include "Util.h"
#include <iostream>

class Sprite
{
public:
	Sprite(SDL_Renderer *passedRenderer, std::string dest, int prior, int x, int y, int width, int height, global_States spriteState);
	Sprite(SDL_Renderer *passedRenderer, std::string dest, int prior, SDL_Rect rect, global_States spriteState);
	int priority;
	global_States state;
	std::string destinationOfImage;
	SDL_Texture *spriteTexture;
	SDL_Rect mainRect;
	void addTextureToMap();
	static std::map<std::string, SDL_Texture *> textureMap;
private:
	SDL_Renderer *renderer;
};

#endif // SPRITE_H
