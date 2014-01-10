#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "SDL.h"
#include <string>

class Background
{
public:
    Background(std::string destinationOfImage);
private:
    SDL_Surface *backgroundImage;
};

#endif //BACKGROUND_H
