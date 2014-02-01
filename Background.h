#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "SDL.h"
#include "layerManager.h"
#include <string>

class Background
{
public:
    Background(SDL_Surface *windowSurface, std::string destinationOfImage);
    ~Background();
};

#endif //BACKGROUND_H
