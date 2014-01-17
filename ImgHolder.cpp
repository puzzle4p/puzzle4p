#include "ImgHolder.h"
ImgHolder::ImgHolder()
{
	images.push_back(SDL_LoadBMP("Images\\blue.bmp"));
	images.push_back(SDL_LoadBMP("Images\\red.bmp"));
	images.push_back(SDL_LoadBMP("Images\\green.bmp"));
	images.push_back(SDL_LoadBMP("Images\\yellow.bmp"));
	images.push_back(SDL_LoadBMP("Images\\white.bmp"));
	images.push_back(SDL_LoadBMP("Images\\blueHighlighted.bmp"));
	images.push_back(SDL_LoadBMP("Images\\redHighlighted.bmp"));
	images.push_back(SDL_LoadBMP("Images\\greenHighlighted.bmp"));
	images.push_back(SDL_LoadBMP("Images\\yellowHighlighted.bmp"));
	images.push_back(SDL_LoadBMP("Images\\whiteHighlighted.bmp"));
}
SDL_Surface* ImgHolder::getImage(int color)
{
	return images[color];
}