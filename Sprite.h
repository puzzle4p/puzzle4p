#ifndef SPRITE_H
#define SPRITE_H

#include "SDL.h"
#include <string>

class Sprite
{
public:
    Sprite(std::string dest, int prior);
    int priority;
    std::string destinationOfImage;
private:
    SDL_Surface *spriteSurface;
};

#endif // SPRITE_H
