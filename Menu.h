#ifndef MENU_H
#define MENU_H

#include "SDL.h"
#include "menu.h"
#include "background.h"
#include "util.h"
#include <string>
#include <iostream>

class Menu
{
public:
    Menu(SDL_Window *mainWindow, std::string destinationOfImage);
    ~Menu();
    void onMouseDown(SDL_Event event, int pointerX, int pointerY);
private:
    SDL_Surface *windowSurface;
    SDL_Surface *backgroundSurface;
};

#endif // MENU_H
