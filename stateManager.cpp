#include "stateManager.h"

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
        std::cout << "CHANGE STATE TO GAME" << std::endl;
    }
    else
    {
        std::cout << "CHANGE STATE TO MENU" << std::endl;
    }
}

void stateManager::addToMap(global_States globalState, State* stateObject)
{
    enumMapToStates[globalState] = stateObject;
}
