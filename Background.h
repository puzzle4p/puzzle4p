#include "SDL.h"
#include <string>

class Background
{
public:
    Background(std::string where);
    SDL_Surface *backgroundImage;
};
