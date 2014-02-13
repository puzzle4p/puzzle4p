#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "SDL.h"
#include "layerManager.h"
#include <string>

class Background
{
public:
    Background(SDL_Surface *windowSurface, SDL_Renderer *passedRenderer, std::string destinationOfImage);
    ~Background();
private:
	SDL_Renderer *renderer;
	Layer *layerBackground;
	Sprite *backgroundSprite;
};

#endif //BACKGROUND_H
