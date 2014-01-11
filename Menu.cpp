#include "Menu.h"

Menu::Menu(SDL_Window *mainWindow, std::string destinationOfImage)
{
    windowSurface = SDL_GetWindowSurface(mainWindow);
    backgroundSurface = new Background(windowSurface, destinationOfImage);
    SDL_UpdateWindowSurface(mainWindow);
}

void Menu::onMouseDown(int pointerX, int pointerY)
{
    std::cout << "Mouse down in menu" << std::endl;
}
