#include "Util.h"
#include "SDL.h"
#include <iostream>
#include <map>

class stateManager
{
public:
    void update();
    void changeState(global_States state);
    void onMouseDown(SDL_Event event, int pointerX, int pointerY);
    void add();
    //std::map<global_States*> currentState;
private:
    global_States current_state;
};
