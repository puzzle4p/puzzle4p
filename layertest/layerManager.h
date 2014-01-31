#ifndef LAYERMANAGER_H
#define LAYERMANAGER_H

#include "SDL.h"
#include "layer.h"
#include <vector>
#include <algorithm>

class layerManager
{
public:
	static void addLayerToVector(int priority);
	static std::vector<layer *> layers;
	static void showLayers(SDL_Renderer *renderer, SDL_Surface *windowSurface);
	~layerManager(); 
private:
	static void sortLayers();
};

#endif //LAYERMANAGER_H

