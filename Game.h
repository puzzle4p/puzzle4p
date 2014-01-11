#include "SDL.h"
#include "State.h"
#include <string>
#include <iostream>

class Game : public State
{
public:
    void onMouseDown(int pointerX, int pointerY);
};
