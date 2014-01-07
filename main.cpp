#include "SDL.h"
#include "Menu.h"
#include "Background.h"

int main(int argc, char* args[]){

bool quit = false;
SDL_Window* gWindow = NULL;
SDL_Event event;

gWindow = SDL_CreateWindow("Nazwa", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
Menu menu(gWindow, "hello.bmp");

while(!quit)
{
    if(SDL_PollEvent(&event))
    {
        quit = menu.onMouseClick(event);
    }
}

SDL_DestroyWindow( gWindow );
gWindow = NULL;

return 0;
}
