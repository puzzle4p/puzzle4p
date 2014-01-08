#include "SDL.h"
#include "Menu.h"
#include "Background.h"

int main(int argc, char* args[]){

SDL_Window* gWindow = NULL;
SDL_Event event;

gWindow = SDL_CreateWindow("Nazwa", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
Menu menu(gWindow, "hello.bmp");

while(true)
{
    if(SDL_PollEvent(&event) && SDL_MOUSEBUTTONDOWN)
    {
        int x = event.button.x;
        int y = event.button.y;

        menu.onMouseDown(event, x, y);
    }
}

SDL_DestroyWindow( gWindow );
gWindow = NULL;

return 0;
}
