#include "ImgHolder.h"
ImgHolder::ImgHolder()
{
	images.push_back(SDL_LoadBMP("Images\\blue.bmp"));
	images.push_back(SDL_LoadBMP("Images\\red.bmp"));
	images.push_back(SDL_LoadBMP("Images\\green.bmp"));
	images.push_back(SDL_LoadBMP("Images\\yellow.bmp"));
	images.push_back(SDL_LoadBMP("Images\\white.bmp"));
}
SDL_Surface* ImgHolder::getImage(Color color)
{
	return images[color];
}