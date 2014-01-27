#ifndef SPRITE_H
#define SPRITE_H

#include "SDL.h"
#include <string>

class sprite
{
public:
    sprite(std::string dest, int prior, int x, int y, int width, int height);
    int priority;
    std::string destinationOfImage;
    SDL_Surface *spriteSurface;
    SDL_Rect rect;
};

#endif // SPRITE_H
