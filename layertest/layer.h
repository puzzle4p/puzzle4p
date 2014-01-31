#ifndef LAYER_H
#define LAYER_H

#include "SDL.h"
#include "sprite.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>


class layer
{
public:
    layer(int priority);
    void addSprite(sprite *s);
    void sortSprites();
    std::vector<sprite*> sprites;
	void showSprites(SDL_Renderer *renderer, SDL_Surface *windowSurface);
	int layerPriority;
private:
	SDL_Texture *bitmapTexture;
	SDL_Surface *bitmapSurface;
};

#endif //LAYER_H