#include "background.h"

Background::Background(SDL_Surface *windowSurface, std::string destinationOfImage)
{
	layerBackground = layerManager::addLayer(-2);
	backgroundSprite = new Sprite(destinationOfImage, 0, 0, 0, windowSurface->w, windowSurface->h);
	layerBackground->addSprite(backgroundSprite);
}

Background::~Background()
{
}
