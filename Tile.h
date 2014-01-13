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
		ImgHolder* images;
	public:
	
		Color color;
		Tile(ImgHolder* imgH);
		Tile(Color color, ImgHolder* imgH);
		~Tile();
		void setImgHolder(ImgHolder* imgH);
		void draw(SDL_Surface* target, int x, int y);
		int getWidth();
		int getHeight();
		bool operator ==(const Tile &t);
};

#endif