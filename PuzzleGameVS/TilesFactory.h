#ifndef TILESFACTORY_H
#define TILESFACTORY_H
#include "Tile.h"
#include "Colors.h"

class TilesFactory
{
	private:
		ImgHolder* images;
	public:
		TilesFactory(ImgHolder* holder);
		TilesFactory(ImgHolder* holder, unsigned int seed);
		Tile* createTile();
		Tile* createTile(Color color);
};

#endif