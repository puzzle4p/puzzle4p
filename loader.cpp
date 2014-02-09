#include "SDL.h"
#include "Menu.h"
#include "Game.h"
#include "stateManager.h"
#include "layerManager.h"
#include <string>


int main(int argc, char* args[])
{
	bool quit = false;
	int windowWidth = 640;
	int windowHeight = 480;
	std::string windowTitle = "puzzle4p";
	std::string menuImageDestination = "menu_background.bmp";
	std::string gameImageDestination = "game_background.bmp";


	SDL_Window *mainWindow = SDL_CreateWindow(windowTitle.c_str(), 100, 100, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED);
	SDL_Surface *windowSurface = SDL_GetWindowSurface(mainWindow);

	layerManager::setRenderer(renderer, windowSurface);

	State *newMenu = new Menu(windowSurface, menuImageDestination);
	State *newGame = new Game(windowSurface, gameImageDestination);

	stateManager::addToMap(STATE_MENU, newMenu);
	stateManager::addToMap(STATE_GAME, newGame);
	stateManager::changeState(STATE_MENU);

	layerManager::showLayers();

	SDL_Event event;
	
	Uint32 currentTicks = SDL_GetTicks();
	const int ticksPerSecond = 1000;
	const int framesPerSecond = 60;

	while (!quit)
	{
		currentTicks = SDL_GetTicks();

		int delay = ticksPerSecond / framesPerSecond - (SDL_GetTicks() - currentTicks);
		if (delay > 0)
		{
			SDL_Delay(delay);
		}

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{				
				stateManager::onMouseDown(event.button.x, event.button.y);
			}
			if (event.type == SDL_TEXTINPUT)
			{
				stateManager::onPressDown(); // funkcja do zrobienia jeszcze
			}
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
		}
	}


	delete newGame;
	delete newMenu;

	SDL_DestroyWindow(mainWindow);
	mainWindow = NULL;

	return 0;
}
