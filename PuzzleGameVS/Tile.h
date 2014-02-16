#ifndef TILE_H
#define TILE_H
#include <SDL.h>
#include "Colors.h"
#include "ImgHolder.h"

class Tile
{
	private:
		SDL_Surface* tileImage;
		int edgeLength;
		bool isHighlighted;
	public:
		//bool toDestroy;
		static ImgHolder images;
		Color color;
		Tile();
		Tile(Color color);
		~Tile();
		void draw(SDL_Surface* target, int x, int y);
		void setHighlight(bool highlight);
		static int getWidth();
		static int getHeight();
		bool operator ==(const Tile &t);
};

#endif
