#include "layerManager.h"

std::vector<Layer *> layerManager::layers;
SDL_Renderer *layerManager::renderer;
SDL_Surface *layerManager::windowSurface;

Layer* layerManager::addLayer(int priority)
{
	Layer *layer = new Layer(priority);
	layers.push_back(layer);
	return layer;
}

//sortowanie tylko chwilowo
struct sortByPriority
{
	bool operator()(Layer *i, Layer *j)
	{
		return i->layerPriority < j->layerPriority;
	}
};

//sortowanie tylko chwilowo
void layerManager::sortLayers()
{
	std::sort(layers.begin(), layers.end(), sortByPriority());
}

void layerManager::setRenderer(SDL_Renderer *mainRenderer, SDL_Surface *mainWindowSurface)
{
	renderer = mainRenderer;
	windowSurface = mainWindowSurface;
}

void layerManager::showLayers()
{
	sortLayers();
	for (std::vector<Layer *>::iterator it = layers.begin(); it != layers.end(); ++it)
	{
		(*it)->showSprites(renderer, windowSurface);
	}

}

layerManager::~layerManager()
{
	for (std::vector<Layer *>::iterator it = layers.begin(); it != layers.end(); ++it)
	{
		delete *it;
	}
}