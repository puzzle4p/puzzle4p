#include "layerManager.h"

std::vector<layer *> layerManager::layers;

void layerManager::addLayerToVector(layer *l)
{
	layers.push_back(l);
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

void layerManager::showLayers(SDL_Surface *windowSurface)
{
	for (unsigned int i = 0; i < layers.size(); i++)
	{
		layers[i]->showSprites(windowSurface);
	}
}