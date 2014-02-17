#ifndef TILE_H
#define TILE_H
#include <SDL.h>
#include "Colors.h"
#include "ImgHolder.h"
#include "drawingManager.h"

class Tile
{
private:
	SDL_Surface* tileImage;
	int edgeLength;
	bool isHighlighted;
	//int w;
	//int h;
public:
	//bool toDestroy;
	ImgHolder *images;
	Color color;
	Tile(ImgHolder* holder);
	Tile(ImgHolder* holder, Color color);
	~Tile();
	void draw(SDL_Renderer* renderer, int x, int y);
	void setHighlight(bool highlight);
	int getWidth();
	int getHeight();
	bool operator ==(const Tile &t);
};

#endif
