#include "Util.h"

bool isPointInsideRectFromMiddle(int pointX, int pointY, int rectX, int rectY, int rectWidth, int rectHeight)
{
	int minX = rectX - rectWidth / 2;
	int minY = rectY - rectHeight / 2;
	int maxX = rectX + rectWidth / 2;
	int maxY = rectY + rectHeight / 2;

	return ((pointX > minX && pointX < maxX) && (pointY > minY && pointY < maxY));
}

bool isPointInsideRectFromMiddle(int pointX, int pointY, SDL_Rect rect)
{
	int minX = rect.x - rect.w / 2;
	int minY = rect.y - rect.h / 2;
	int maxX = rect.x + rect.w / 2;
	int maxY = rect.y + rect.h / 2;

	return ((pointX > minX && pointX < maxX) && (pointY > minY && pointY < maxY));
}

bool isPointInsideRectFromCorner(int pointX, int pointY, int rectX, int rectY, int rectWidth, int rectHeight)
{
    int minX = rectX;
    int minY = rectY;
    int maxX = rectX + rectWidth;
    int maxY = rectY + rectHeight;

    return ((pointX > minX && pointX < maxX) && (pointY > minY && pointY < maxY));
}

bool isPointInsideRectFromCorner(int pointX, int pointY, SDL_Rect rect)
{
	int minX = rect.x;
	int minY = rect.y;
	int maxX = rect.x + rect.w;
	int maxY = rect.y + rect.h;

	return ((pointX > minX && pointX < maxX) && (pointY > minY && pointY < maxY));
}