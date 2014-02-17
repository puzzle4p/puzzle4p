#include "TilesFactory.h"
#include "ImgHolder.h"
#include <cstdlib>
#include <ctime>
TilesFactory::TilesFactory(ImgHolder* holder)
{
	images = holder;
	srand(time(NULL));
}
TilesFactory::TilesFactory(ImgHolder* holder, unsigned int seed)
{
	images = holder;
	srand(seed);
}
Tile* TilesFactory::createTile()
{
	return new Tile(images);
}
Tile* TilesFactory::createTile(Color color)
{
	return new Tile(images, color);
}