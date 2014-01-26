#ifndef MENU_H
#define MENU_H

#include <string>
#include "SDL.h"
#include "Menu.h"
#include "Background.h"
#include "Util.h"
#include "State.h"
#include "Gui.h"
#include "Button.h"
#include "Layer.h"
#include "Sprite.h"
#include <vector>
#include <string>
#include <iostream>

class Menu : public State
{
public:
    Menu(SDL_Window *mainWindow, std::string destinationOfImage);
    ~Menu();
    void onMouseDown(int pointerX, int pointerY);
private:
    Background *backgroundSurface;
    SDL_Surface *windowSurface;
    std::vector<Button*> buttons;
};

#endif // MENU_H
