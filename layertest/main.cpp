#include "SDL.h"
#include "layer.h"
#include "layerManager.h"
#include "sprite.h"
#include <string>
#include <iostream>

int main(int argc, char* args[])
{
    bool quit = false;
    int windowWidth = 640;
    int windowHeight = 480;
    std::string windowTitle = "puzzle4p";
    std::string destinationOfImage = "hello.bmp";

    SDL_Window *mainWindow = SDL_CreateWindow(windowTitle.c_str(), 100, 100, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
	SDL_Surface *windowSurface = SDL_GetWindowSurface(mainWindow);
    SDL_Event event;

	layerManager::addLayerToVector(new layer(1));
	layerManager::layers[0]->addSprite(new sprite("red.bmp", 0, 0, 0, 100, 100));
	layerManager::addLayerToVector(new layer(0));
	layerManager::layers[1]->addSprite(new sprite("hello.bmp", 0, 0, 0, 100, 100));

	layerManager::sortLayers();
	layerManager::showLayers(windowSurface);

	
	

	



    /*layer *l = new layer();
    sprite *s1 = new sprite("red.bmp", 4, 100, 100, 100, 100);
    l->addSprite(s1);
    sprite *s2 = new sprite("hello.bmp", 1, 0, 0, 640, 480);
    l->addSprite(s2);

    l->sortSprites();
    l->showSprites(windowSurface);*/
    SDL_UpdateWindowSurface(mainWindow);

    while(!quit)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                int x = event.button.x;
                int y = event.button.y;

                std::cout << x << " : " << y << std::endl;
            }
            if(event.type == SDL_TEXTINPUT)
            {
                std::cout << event.text.text;
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
