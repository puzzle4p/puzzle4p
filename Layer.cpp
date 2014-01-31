#include "layer.h"

Layer::Layer(int priority)
{
	layerPriority = priority;
}

void Layer::addSprite(Sprite *s)
{
	sprites.push_back(s);
}

struct sortByPriority
{
	bool operator()(Sprite *i, Sprite *j)
	{
		return i->priority < j->priority;
	}
};

void Layer::sortSprites()
{
	std::sort(sprites.begin(), sprites.end(), sortByPriority());
}

void Layer::showSprites(SDL_Renderer *renderer, SDL_Surface *windowSurface)
{
	for (std::vector<Sprite *>::iterator it = sprites.begin(); it != sprites.end(); ++it)
	{
		bitmapSurface = (*it)->spriteSurface;
		bitmapTexture = SDL_CreateTextureFromSurface(renderer, bitmapSurface);

		SDL_RenderCopy(renderer, bitmapTexture, NULL, &((*it)->rect));
		SDL_FreeSurface(bitmapSurface);
	}
	SDL_RenderPresent(renderer);
}
