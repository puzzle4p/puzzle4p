#include "Util.h"

bool Util::isPointInsideRect(int pointX, int pointY, int rectX, int rectY, int rectWidth, int rectHeight)
{
    int minX = rectX - rectWidth / 2;
    int minY = rectY - rectHeight / 2;
    int maxX = rectX + rectWidth / 2;
    int maxY = rectY + rectHeight / 2;

    return ((pointX > minX && pointX < maxX) && (pointY > minY && pointY < maxY));
}
