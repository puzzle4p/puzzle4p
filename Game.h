#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "State.h"
#include "Util.h"
#include "Background.h"
#include "stateManager.h"

class Game : public State
{
public:
	Game(SDL_Window *mainWindow, SDL_Surface *windowSurface, SDL_Renderer *passedRenderer, std::string destinationOfImage);
    void onMouseDown(int pointerX, int pointerY);
	void update();
private:
	SDL_Renderer *renderer;
	Layer *layerButton;
	Sprite *startGameButton;
	Background *backgroundSurface;
};

#endif //GAME_H