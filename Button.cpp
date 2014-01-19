#include "Button.h"

Button::Button(int x, int y, int width, int height, SDL_Surface *buttonSurface, SDL_Surface *windowSurface)
{
    buttonImage = buttonSurface;
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;

    SDL_BlitSurface(buttonImage, NULL, windowSurface, &rect);
}
