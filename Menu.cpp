#include "Menu.h"

Menu::Menu(SDL_Window *mainWindow, std::string destinationOfImage)
{
    windowSurface = SDL_GetWindowSurface(mainWindow);
    backgroundSurface = new Background(windowSurface, destinationOfImage);
    SDL_UpdateWindowSurface(mainWindow);
}

void Menu::onMouseDown(int pointerX, int pointerY)
{
    if(isPointInsideRect(pointerX, pointerY, 100, 100, 100, 100))
    {
        std::cout << "X:" << pointerX << " Y:" << pointerY << std::endl;
    }
}
