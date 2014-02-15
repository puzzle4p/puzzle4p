#ifndef LAYERMANAGER_H
#define LAYERMANAGER_H

#include "SDL.h"
#include "Layer.h"
#include <vector>
#include <algorithm>

class layerManager
{
public:
	static Layer* addLayer(int priority);
	static std::vector<Layer *> layers;
	static void setRenderer(SDL_Renderer *renderer, SDL_Surface *mainWindowSurface);
	static void showLayers();
	~layerManager();
private:
	static void sortLayers();
	static SDL_Renderer *renderer;
	static SDL_Surface *windowSurface;
};

#endif //LAYERMANAGER_H