#include "Menu.h"

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

void Menu::onMouseDown(SDL_Event event, int pointerX, int pointerY)
{
    std::cout << "Mouse down in menu" << std::endl;
    if(event.button.button == SDL_BUTTON_LEFT)
    {
        if(isPointInsideRect(pointerX, pointerY, 50, 50, 100, 100))
        {
            std::cout << pointerX << " | " << pointerY << " -- in\n";
        }
    }
}
