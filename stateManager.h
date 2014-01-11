#include "Util.h"
#include "SDL.h"
#include "State.h"
#include <iostream>
#include <map>

class stateManager
{
public:
    static void update();
    static void changeState(global_States state);
    static void onMouseDown(int pointerX, int pointerY);
    static std::map<global_States, State*> enumMapToStates;
    static void addToMap(global_States globalState, State* stateObject);
private:
    static global_States current_state;

};
