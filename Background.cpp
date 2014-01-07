#include "Background.h"
#include <string>

Background::Background(std::string where)
{
    backgroundImage = SDL_LoadBMP(where.c_str());
}
