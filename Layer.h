#ifndef LAYER_H
#define LAYER_H

#include "SDL.h"
#include "Sprite.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>


class Layer
{
public:
	Layer(int priority);
	void addSprite(Sprite *s);
	void sortSprites();
	std::vector<Sprite*> sprites;
	void showSprites(SDL_Renderer *renderer, SDL_Surface *windowSurface);
	int layerPriority;
private:
	SDL_Texture *bitmapTexture;
	SDL_Surface *bitmapSurface;
};

#endif //LAYER_H