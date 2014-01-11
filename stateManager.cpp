#include "stateManager.h"

void stateManager::update()
{

}

void stateManager::onMouseDown()
{

}

void stateManager::changeState(global_States state)
{
    if(!state)
    {

    }
    current_state = state;

    if(current_state == game)
    {
        std::cout << "game";
    }
    else
    {
        std::cout << "menu";
    }
}
