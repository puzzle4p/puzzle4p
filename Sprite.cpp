#include "Sprite.h"

Sprite::Sprite(std::string dest, int prior)
{
    destinationOfImage = dest;
    priority = prior;
    SDL_Surface *spriteSurface = SDL_LoadBMP(destinationOfImage.c_str());
}
