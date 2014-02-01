#ifndef MENU_H
#define MENU_H

#include "SDL.h"
#include "Background.h"
#include "Util.h"
#include "State.h"
#include "Button.h"
#include "layerManager.h"
#include "Sprite.h"
#include <vector>
#include <string>

class Menu : public State
{
public:
    Menu(SDL_Surface *windowSurface, std::string destinationOfImage);
    ~Menu();
    void onMouseDown(int pointerX, int pointerY);
private:
    Background *backgroundSurface;
    std::vector<Button*> buttons;
	Button *b;
};

#endif // MENU_H
