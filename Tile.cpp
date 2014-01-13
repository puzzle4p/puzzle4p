#include "Tile.h"
#include <cstdlib>
#include <ctime>
#include <string>
Tile::Tile(ImgHolder* imgH)
{
	color = static_cast<Color>(rand() % NUM_COLORS);
	images = imgH;
}
Tile::Tile(Color color, ImgHolder* imgH)
{
	this -> color = color;
	images = imgH;
}
Tile::~Tile()
{
}
void Tile::draw(SDL_Surface* target, int x, int y)
{
	SDL_Rect targetRect;
	targetRect.x = x;
	targetRect.y = y;
	SDL_BlitSurface(images -> getImage(color), NULL, target, &targetRect);
}
int Tile::getWidth()
{
	return 60;
}
int Tile::getHeight()
{
	return 60;
}
bool Tile::operator ==(const Tile &t)
{
	if(color == t.color)
	{
		return true;
	}
	return false;
}