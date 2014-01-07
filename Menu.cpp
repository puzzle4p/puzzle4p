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

void Menu::onMouseClick(SDL_Event event)
{
    int x = 0,y = 0;
    if(event.type == SDL_MOUSEBUTTONUP)
    {
        if(event.button.button == SDL_BUTTON_LEFT)
        {
            x = event.button.x;
            y = event.button.y;

            if(x > 0 && x < 640 && y > 0 && y < 480)
            {
                std::cout << "x:" << x << " | y:" << y << std::endl;
            }
        }
    }
}
