#include "Background.h"
#include <string>

Background::Background(std::string destinationOfImage)
{
    backgroundImage = SDL_LoadBMP(destinationOfImage.c_str());
}
