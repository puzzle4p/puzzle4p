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
	Menu(SDL_Window *mainWindow, SDL_Renderer *passed_renderer, SDL_Surface *windowSurface, std::string destinationOfImage);
    ~Menu();
    void onMouseDown(int pointerX, int pointerY);
	void update();
private:
	SDL_Renderer *renderer;
	Layer *layerButton;
	Sprite *title;
	Sprite *startGameButton;
	Sprite *quitButton;
    Background *backgroundSurface;
	global_States state;
};

#endif // MENU_H
