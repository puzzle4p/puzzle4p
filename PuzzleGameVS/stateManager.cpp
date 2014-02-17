#include "stateManager.h"
#include "layerManager.h"

global_States stateManager::current_state;
std::map<global_States, State*> stateManager::enumMapToStates;

void stateManager::update()
{
	enumMapToStates[current_state]->update();
}

void stateManager::onMouseDown(int pointerX, int pointerY)
{
	enumMapToStates[current_state]->onMouseDown(pointerX, pointerY);
}

void stateManager::changeState(global_States state)
{
    current_state = state;
}

void stateManager::addToMap(global_States globalState, State* stateObject)
{
    enumMapToStates[globalState] = stateObject;
}

void stateManager::onPressDown()
{
	//to be done
}