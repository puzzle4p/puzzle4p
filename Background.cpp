#include "background.h"

Background::Background(std::string destinationOfImage)
{
    backgroundImage = SDL_LoadBMP(destinationOfImage.c_str());
}
