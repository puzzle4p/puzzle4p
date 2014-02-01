#include "background.h"

Background::Background(SDL_Surface *windowSurface, std::string destinationOfImage)
{
	layerManager::layers[0]->addSprite(new Sprite(destinationOfImage, 0, 0, 0, windowSurface->w, windowSurface->h));
}

Background::~Background()
{
}
