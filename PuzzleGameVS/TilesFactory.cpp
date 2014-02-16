#include "TilesFactory.h"
#include "ImgHolder.h"
#include <cstdlib>
#include <ctime>
TilesFactory::TilesFactory()
{
	srand(time(NULL));
}
TilesFactory::TilesFactory(unsigned int seed)
{
	srand(seed);
}
Tile* TilesFactory::createTile()
{
	return new Tile();
}
Tile* TilesFactory::createTile(Color color)
{
	return new Tile(color);
}