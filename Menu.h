#ifndef MENU_H
#define MENU_H

#include "SDL.h"
#include "Background.h"
#include "Util.h"
#include "State.h"
#include "layerManager.h"
#include "stateManager.h"
#include "Sprite.h"
#include <vector>
#include <string>

class Menu : public State
{
public:
	Menu(SDL_Window *mainWindow, SDL_Surface *windowSurface, SDL_Renderer *passedRenderer, std::string destinationOfImage);
    ~Menu();
    void onMouseDown(int pointerX, int pointerY);
private:
	SDL_Renderer *renderer;
	Layer *layerButton;
	Sprite *startGameButton;
    Background *backgroundSurface;
};

#endif // MENU_H
