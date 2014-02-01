#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "State.h"

class Game : public State
{
public:
    void onMouseDown(int pointerX, int pointerY);
};

#endif //GAME_H