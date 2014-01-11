#include "stateManager.h"

void stateManager::update()
{

}

void stateManager::onMouseDown(SDL_Event event, int pointerX, int pointerY)
{
    std::cout << "Mouse down in stateManager" << std::endl;
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
