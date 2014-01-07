#include "SDL.h"
#include "Menu.h"
#include "Background.h"
#include <string>
#include <iostream>

Menu::Menu(SDL_Window *mainWindow, std::string destinationOfImage)
{
    windowSurface = SDL_GetWindowSurface(mainWindow);
    backgroundSurface = SDL_LoadBMP(destinationOfImage.c_str());

    SDL_BlitSurface(backgroundSurface, NULL, windowSurface, NULL );
    SDL_UpdateWindowSurface(mainWindow);
}

Menu::~Menu()
{
    SDL_FreeSurface(backgroundSurface);
    backgroundSurface = NULL;
}

bool Menu::onMouseClick(SDL_Event event)
{
    if(event.type == SDL_MOUSEBUTTONUP)
    {
        if(event.button.button == SDL_BUTTON_LEFT)
        {
            return true;
        }
    }
    return false;
}
