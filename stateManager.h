#include "Util.h"
#include "SDL.h"
#include "State.h"
#include <iostream>
#include <map>

class stateManager
{
public:
    void update();
    void changeState(global_States state);
    void onMouseDown(SDL_Event event, int pointerX, int pointerY);
    std::map<global_States, State*> enumMapToStates;
    void addToMap(global_States globalState, State* stateObject);
private:
    global_States current_state;

};
