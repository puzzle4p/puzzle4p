#include "SDL.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

class layer
{
public:
    void addLayer(std::string destinationOfImage, int priority);
    void showLayers(SDL_Renderer *renderer);
private:
    std::vector<SDL_Surface*> layers;
};
