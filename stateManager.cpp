#include "stateManager.h"

void stateManager::update()
{

}

void stateManager::onMouseDown(SDL_Event event, int pointerX, int pointerY)
{
    enumMapToStates[current_state]->onMouseDown(event, pointerX, pointerY);
}

void stateManager::changeState(global_States state)
{
    if(!state)
    {

    }
    current_state = state;

    if(current_state == STATE_GAME)
    {
        std::cout << "game";
    }
    else
    {
        std::cout << "menu";
    }
}

void stateManager::addToMap(global_States globalState, State* stateObject)
{
    enumMapToStates[globalState] = stateObject;
}
