#ifndef TILESFACTORY_H
#define TILESFACTORY_H
#include "Tile.h"
#include "Colors.h"

class TilesFactory
{
	private:
		ImgHolder* imgH;
	public:
		TilesFactory();
		Tile* createTile();
		Tile* createTile(Color color);
};

#endif