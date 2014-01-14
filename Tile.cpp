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
	return images -> getImage(color) -> w;
}
int Tile::getHeight()
{
	return images -> getImage(color) -> h;
}
bool Tile::operator ==(const Tile &t)
{
	if(color == t.color)
	{
		return true;
	}
	return false;
}