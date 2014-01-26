#include "Button.h"

Button::Button(int x, int y, int width, int height, std::string buttonImageDestination, SDL_Surface *windowSurface)
{
    rect.x = x - (width / 2);
    rect.y = y - (height / 2);
    rect.w = width;
    rect.h = height;

    buttonImage = SDL_LoadBMP(buttonImageDestination.c_str());
    SDL_BlitSurface(buttonImage, NULL, windowSurface, &rect);
}
