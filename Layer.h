#ifndef LAYER_H
#define LAYER_H

#include "SDL.h"
#include "Sprite.h"
#include <vector>
#include <algorithm>
#include <map>


class Layer
{
public:
	Layer(int priority);
	void addSprite(Sprite *s);
	void sortSprites();
	std::vector<Sprite*> sprites;
	void showSprites(SDL_Renderer *renderer, SDL_Surface *windowSurface);
	int layerPriority;
	void destroyLayer();
private:
	SDL_Texture *bitmapTexture;
	SDL_Surface *bitmapSurface;
	std::map<std::string, SDL_Texture*> textureMap;
};

#endif //LAYER_H