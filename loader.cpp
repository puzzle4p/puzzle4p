#include "SDL.h"
#include "Menu.h"
#include "Game.h"
#include "Background.h"
#include "Util.h"
#include "stateManager.h"
#include <iostream>
#include <string>


int main(int argc, char* args[])
{
    bool quit = false;
    int windowWidth = 640;
    int windowHeight = 480;
    std::string windowTitle = "puzzle4p";

    SDL_Window* mainWindow = SDL_CreateWindow(windowTitle.c_str(), 100, 100, windowWidth, windowHeight, SDL_WINDOW_SHOWN);

    stateManager::addToMap(STATE_MENU, new Menu(mainWindow, "hello.bmp"));
    stateManager::addToMap(STATE_GAME, new Game());

    stateManager::changeState(STATE_MENU);

    SDL_Event event;

    while(!quit)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                int x = event.button.x;
                int y = event.button.y;

                stateManager::onMouseDown(x, y);
            }
            if(event.type == SDL_TEXTINPUT)
            {
                std::cout << event.text.text;
                stateManager::changeState(STATE_GAME);
            }
            if(event.type == SDL_QUIT)
            {
                quit = true;
            }
        }
    }

    SDL_DestroyWindow( mainWindow );
    mainWindow = NULL;

    return 0;
}
