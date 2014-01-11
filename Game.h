#include "SDL.h"
#include "State.h"
#include <string>
#include <iostream>

class Game : public State
{
public:
    void onMouseDown(SDL_Event event, int pointerX, int pointerY);
};
