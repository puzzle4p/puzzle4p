#include "layer.h"

void layer::addLayer(std::string destinationOfImage, int priority)
{
    SDL_Surface *surface = SDL_LoadBMP(destinationOfImage.c_str());
    layers[priority] = surface;
}

void layer::showLayers(SDL_Renderer *renderer)
{
    for(int i = 0; i < 3; i++)
    {
        if(layers[i])
        {
            SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, layers[i]);

            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, texture, NULL, NULL);
            SDL_RenderPresent(renderer);
        }
    }
}
