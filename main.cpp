#include "SDL.h"
#include "Menu.h"
#include "Background.h"
#include <iostream>

int main(int argc, char* args[])
{
bool quit = false;
SDL_Window* gWindow = NULL;
SDL_Event event;

gWindow = SDL_CreateWindow("Nazwa", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
Menu menu(gWindow, "hello.bmp");

while(!quit)
{
    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_MOUSEBUTTONDOWN)
        {
            int x = event.button.x;
            int y = event.button.y;

            menu.onMouseDown(event, x, y);
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

SDL_DestroyWindow( gWindow );
gWindow = NULL;

return 0;
}
