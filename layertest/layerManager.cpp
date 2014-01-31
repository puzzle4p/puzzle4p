#include "layerManager.h"

std::vector<layer *> layerManager::layers;

void layerManager::addLayerToVector(int priority)
{
	layers.push_back(new layer(priority));
}

struct sortByPriority
{
	bool operator()(layer *i, layer *j)
	{
		return i->layerPriority < j->layerPriority;
	}
};

void layerManager::sortLayers()
{
	std::sort(layers.begin(), layers.end(), sortByPriority());
}

void layerManager::showLayers(SDL_Renderer *renderer, SDL_Surface *windowSurface)
{
	sortLayers();
	for (unsigned int i = 0; i < layers.size(); i++)
	{
		layers[i]->showSprites(renderer, windowSurface);
	}
}

layerManager::~layerManager()
{
	for (unsigned int i = 0; i < layers.size(); i++)
	{
		delete layers[i];
	}
}