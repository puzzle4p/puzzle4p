#include "Tile.h"
#include <cstdlib>
#include <ctime>
#include <string>
ImgHolder Tile::images = ImgHolder();
Tile::Tile()
{
	color = static_cast<Color>(rand() % 5);
	isHighlighted = false;
	//toDestroy = false;
}
Tile::Tile(Color color)
{
	this -> color = color;
	isHighlighted = false;
	//toDestroy = false;
}
Tile::~Tile()
{
}
void Tile::draw(SDL_Surface* target, int x, int y)
{
	SDL_Rect targetRect;
	targetRect.x = x;
	targetRect.y = y;
	if(!isHighlighted)
	{
		SDL_BlitSurface(Tile::images.getImage(color), NULL, target, &targetRect);
	}
	else
	{
		SDL_BlitSurface(Tile::images.getImage(color + 5), NULL, target, &targetRect);
	}
}
int Tile::getWidth()
{
	return 60;
}
int Tile::getHeight()
{
	return 60;
}
void Tile::setHighlight(bool highlight)
{
	isHighlighted = highlight;
}
bool Tile::operator ==(const Tile &t)
{
	if(color == t.color)
	{
		return true;
	}
	return false;
}
