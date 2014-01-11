#include "background.h"

Background::Background(SDL_Surface *windowSurface, std::string destinationOfImage)
{
    backgroundImage = SDL_LoadBMP(destinationOfImage.c_str());

    SDL_BlitSurface(backgroundImage, NULL, windowSurface, NULL );
}

Background::~Background()
{
    SDL_FreeSurface(backgroundImage);
    backgroundImage = NULL;
}
