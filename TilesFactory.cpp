#include "TilesFactory.h"
#include "ImgHolder.h"
TilesFactory::TilesFactory()
{	
	imgH = new ImgHolder();
}
Tile* TilesFactory::createTile()
{
	return new Tile(imgH);
}
Tile* TilesFactory::createTile(Color color)
{
	return new Tile(color, imgH);
}