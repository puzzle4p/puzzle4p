#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "SDL.h"
#include <string>

class Background
{
public:
    Background(SDL_Surface *windowSurface, std::string destinationOfImage);
    ~Background();
private:
    SDL_Surface *backgroundImage;
};

#endif //BACKGROUND_H
