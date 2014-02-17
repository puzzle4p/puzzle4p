#include "Tile.h"
#include <cstdlib>
#include <ctime>
#include <string>
#define WIDTH 70
#define HEIGHT 70

Tile::Tile(ImgHolder* holder)
{
	images = holder;
	color = static_cast<Color>(rand() % 5);
	isHighlighted = false;
	//SDL_QueryTexture(images->getImage(color), NULL, NULL, &w, &h);
}
Tile::Tile(ImgHolder* holder, Color color)
{
	images = holder;
	this->color = color;
	isHighlighted = false;
	//SDL_QueryTexture(images->getImage(color), NULL, NULL, &w, &h);
}
Tile::~Tile()
{
}
void Tile::draw(SDL_Renderer* renderer, int x, int y)
{
	SDL_Rect targetRect;
	targetRect.x = x;
	targetRect.y = y;
	targetRect.w = WIDTH;
	targetRect.h = HEIGHT;
	if (!isHighlighted)
	{
		SDL_RenderCopy(renderer, images->getImage(color), NULL, &targetRect);
	}
	else
	{
		SDL_RenderCopy(renderer, images->getImage(color + 5), NULL, &targetRect);
	}
}
int Tile::getWidth()
{
	return WIDTH;
}
int Tile::getHeight()
{
	return HEIGHT;
}
void Tile::setHighlight(bool highlight)
{
	isHighlighted = highlight;
}
bool Tile::operator ==(const Tile &t)
{
	if (color == t.color)
	{
		return true;
	}
	return false;
}