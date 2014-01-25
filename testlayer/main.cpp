#include "SDL.h"
#include "layer.h"
#include <string>
#include <iostream>

int main(int argc, char* args[])
{
    layer layer11;

    bool quit = false;
    int windowWidth = 640;
    int windowHeight = 480;
    std::string windowTitle = "puzzle4p";
    std::string destinationOfImage = "hello.bmp";

    SDL_Window* mainWindow = SDL_CreateWindow(windowTitle.c_str(), 100, 100, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED);

    layer11.addLayer("red.bmp", 0);
    layer11.addLayer("hello.bmp", 1);
    layer11.showLayers(renderer);

    SDL_Event event;

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
