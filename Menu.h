#ifndef MENU_H
#define MENU_H

#include <string>
#include "SDL.h"
#include "Menu.h"
#include "Background.h"
#include "Util.h"
#include "State.h"
#include <string>
#include <iostream>

class Menu : public State
{
public:
    Menu(SDL_Window *mainWindow, std::string destinationOfImage);
    ~Menu();
    void onMouseDown(int pointerX, int pointerY);
private:
    SDL_Surface *windowSurface;
    SDL_Surface *backgroundSurface;
};

#endif // MENU_H
