#include "SDL.h"
#include "Menu.h"
#include "Game.h"
#include "Quit.h"
#include "layerManager.h"
#include "drawingManager.h"
#include <string>
#include <iostream>


int main(int argc, char* args[])
{
	bool quit = false;
	int windowWidth = 1280;
	int windowHeight = 720;
	int boardSize = 8;
	std::string windowTitle = "puzzle4p";
	std::string menuImageDestination = "Images//MAIN_MENU_BG.png";
	std::string gameImageDestination = "Images/game_background.bmp";
	drawingManager::window = SDL_CreateWindow(windowTitle.c_str(), 100, 100, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
	SDL_Surface *windowSurface = SDL_GetWindowSurface(drawingManager::window);
	drawingManager::renderer = SDL_CreateRenderer(drawingManager::window, -1, SDL_RENDERER_ACCELERATED);

	State *newMenu = new Menu(drawingManager::window, drawingManager::renderer, windowSurface, menuImageDestination);
	State *newGame = NULL;
	State *quitState = new Quit();

	stateManager::addToMap(STATE_MENU, newMenu);
	stateManager::addToMap(STATE_GAME, newGame);
	stateManager::addToMap(STATE_QUIT, quitState);
	stateManager::changeState(STATE_MENU);

	SDL_Event event;
	
	Uint32 currentTicks = SDL_GetTicks();
	const int ticksPerSecond = 1000;
	const int framesPerSecond = 60;
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
	}
	while (!quit)
	{
		currentTicks = SDL_GetTicks();

		int delay = ticksPerSecond / framesPerSecond - (SDL_GetTicks() - currentTicks);
		if (delay > 0)
		{
			SDL_Delay(delay);
		}


		if (stateManager::enumMapToStates[STATE_GAME] == NULL && stateManager::current_state == STATE_GAME)
		{
			stateManager::enumMapToStates[STATE_GAME] = new Game(drawingManager::window, drawingManager::renderer, windowSurface, gameImageDestination, boardSize);
		}

		if (stateManager::current_state == STATE_MENU && stateManager::enumMapToStates[STATE_GAME] != NULL)
		{
			delete stateManager::enumMapToStates[STATE_GAME];
			stateManager::enumMapToStates[STATE_GAME] = NULL;
		}
		if (stateManager::current_state == STATE_QUIT)
		{
			quit = true;
		}
		layerManager::setRenderer(drawingManager::renderer, windowSurface);
		layerManager::showLayers();
		SDL_RenderPresent(drawingManager::renderer);
		stateManager::update();

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

	SDL_DestroyWindow(drawingManager::window);
	drawingManager::window = NULL;

	return 0;
}