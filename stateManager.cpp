#include "stateManager.h"

global_States stateManager::current_state;
std::map<global_States, State*> stateManager::enumMapToStates;

void stateManager::update()
{

}

void stateManager::onMouseDown(int pointerX, int pointerY)
{
    enumMapToStates[current_state]->onMouseDown(pointerX, pointerY);
}

void stateManager::changeState(global_States state)
{
    if(!state)
    {

    }
    current_state = state;

    if(current_state == STATE_GAME)
    {
        
    }
    else
    {
        
    }
}

void stateManager::addToMap(global_States globalState, State* stateObject)
{
    enumMapToStates[globalState] = stateObject;
}
