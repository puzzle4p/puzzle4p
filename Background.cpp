#include "background.h"

Background::Background(SDL_Surface *windowSurface, SDL_Renderer *passedRenderer, std::string destinationOfImage, global_States state)
{
	renderer = passedRenderer;
	layerBackground = layerManager::addLayer(-2);
	backgroundSprite = new Sprite(renderer, destinationOfImage, 0, 0, 0, windowSurface->w, windowSurface->h, state);
	layerBackground->addSprite(backgroundSprite);
}

Background::~Background()
{
	
}
