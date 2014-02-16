#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "SDL.h"
#include "layerManager.h"
#include <string>

class Background
{
public:
    Background(SDL_Surface *windowSurface, SDL_Renderer *renderer, std::string destinationOfImage, global_States state);
    ~Background();
private:
	Layer *layerBackground;
	Sprite *backgroundSprite;
};

#endif //BACKGROUND_H
