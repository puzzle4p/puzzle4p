#include "SDL.h"
#include <string>

class Background
{
public:
    Background(std::string destinationOfImage);
private:
    SDL_Surface *backgroundImage;
};
