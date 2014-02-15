#include "layer.h"
#include <iostream>

Layer::Layer(int priority)
{
	layerPriority = priority;
}

void Layer::addSprite(Sprite *s)
{
	sprites.push_back(s);
}

//sortowanie tylko chwilowo
struct sortByPriority
{
	bool operator()(Sprite *i, Sprite *j)
	{
		return i->priority < j->priority;
	}
};

//sortowanie tylko chwilowo
void Layer::sortSprites()
{
	std::sort(sprites.begin(), sprites.end(), sortByPriority());
}

void Layer::showSprites(SDL_Renderer *renderer, SDL_Surface *windowSurface)
{
	if (renderer)
	{
		for (std::vector<Sprite *>::iterator it = sprites.begin(); it != sprites.end(); ++it)
		{
			std::cout << "Wyswietlam teksture: " << (*it)->destinationOfImage << std::endl;
			SDL_RenderCopy(renderer, (*it)->spriteTexture, NULL, &((*it)->mainRect));
		}
		SDL_RenderPresent(renderer);
	}
}