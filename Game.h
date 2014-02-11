#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "State.h"
#include "Background.h"

class Game : public State
{
public:
	Game(SDL_Window *mainWindow, SDL_Surface *windowSurface, std::string destinationOfImage);
    void onMouseDown(int pointerX, int pointerY);
	void update();
private:
	Background *backgroundSurface;
	SDL_Renderer *renderer;
};

#endif //GAME_H