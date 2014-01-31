#include "layer.h"

layer::layer(int priority)
{
	layerPriority = priority;
}

void layer::addSprite(sprite *s)
{
    sprites.push_back(s);
}

struct sortByPriority
{
    bool operator()(sprite *i, sprite *j)
    {
        return i->priority < j->priority;
    }
};

void layer::sortSprites()
{
    std::sort(sprites.begin(), sprites.end(), sortByPriority());
}

void layer::showSprites(SDL_Renderer *renderer, SDL_Surface *windowSurface)
{
    for(unsigned int i = 0; i < sprites.size(); i++)
    {
		bitmapSurface = sprites[i]->spriteSurface;
		bitmapTexture = SDL_CreateTextureFromSurface(renderer, bitmapSurface);
		
		SDL_RenderCopy(renderer, bitmapTexture, NULL, &(sprites[i]->rect));
		SDL_FreeSurface(bitmapSurface);
    }
	SDL_RenderPresent(renderer);
}
