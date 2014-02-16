#include "ImgHolder.h"
ImgHolder::ImgHolder()
{
	images.push_back(SDL_LoadBMP("Images/tiles/blue.bmp"));
	images.push_back(SDL_LoadBMP("Images/tiles/red.bmp"));
	images.push_back(SDL_LoadBMP("Images/tiles/green.bmp"));
	images.push_back(SDL_LoadBMP("Images/tiles/yellow.bmp"));
	images.push_back(SDL_LoadBMP("Images/tiles/white.bmp"));
	images.push_back(SDL_LoadBMP("Images/tiles/blueHighlighted.bmp"));
	images.push_back(SDL_LoadBMP("Images/tiles/redHighlighted.bmp"));
	images.push_back(SDL_LoadBMP("Images/tiles/greenHighlighted.bmp"));
	images.push_back(SDL_LoadBMP("Images/tiles/yellowHighlighted.bmp"));
	images.push_back(SDL_LoadBMP("Images/tiles/whiteHighlighted.bmp"));
}
SDL_Surface* ImgHolder::getImage(int color)
{
	return images[color];
}