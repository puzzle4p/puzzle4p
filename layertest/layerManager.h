#ifndef LAYERMANAGER_H
#define LAYERMANAGER_H

#include "SDL.h"
#include "layer.h"
#include <vector>
#include <algorithm>

class layerManager
{
public:
	static void addLayerToVector(layer *l);
	static std::vector<layer *> layers;
	static void sortLayers();
	static void showLayers(SDL_Surface *windowSurface);
};

#endif //LAYERMANAGER_H

