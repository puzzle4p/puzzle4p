#ifndef TILESFACTORY_H
#define TILESFACTORY_H
#include "Tile.h"
#include "Colors.h"

class TilesFactory
{
	public:
		TilesFactory();
		TilesFactory(unsigned int seed);
		Tile* createTile();
		Tile* createTile(Color color);
};

#endif