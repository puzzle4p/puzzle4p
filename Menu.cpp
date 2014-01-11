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

void Menu::onMouseDown(int pointerX, int pointerY)
{
    std::cout << "Mouse down in menu" << std::endl;
}
