#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "State.h"
#include "Background.h"

class Game : public State
{
public:
	Game(SDL_Surface *windowSurface, std::string destinationOfImage);
    void onMouseDown(int pointerX, int pointerY);
	void update();
private:
	Background *backgroundSurface;
};

#endif //GAME_H