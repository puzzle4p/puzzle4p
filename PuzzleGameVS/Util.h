#ifndef UTIL_H
#define UTIL_H

#include "SDL.h"

enum global_States {STATE_MENU, STATE_GAME, STATE_QUIT};
bool isPointInsideRectFromMiddle(int pointX, int pointY, int rectX, int rectY, int rectWidth, int rectHeight);
bool isPointInsideRectFromMiddle(int pointX, int pointY, SDL_Rect rect);
bool isPointInsideRectFromCorner(int pointX, int pointY, int rectX, int rectY, int rectWidth, int rectHeight);
bool isPointInsideRectFromCorner(int pointX, int pointY, SDL_Rect rect);

#endif //UTIL_H
