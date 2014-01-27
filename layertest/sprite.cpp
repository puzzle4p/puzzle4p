#include "sprite.h"

sprite::sprite(std::string dest, int prior, int x, int y, int width, int height)
{
    destinationOfImage = dest;
    priority = prior;
    spriteSurface = SDL_LoadBMP(destinationOfImage.c_str());
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;
}
