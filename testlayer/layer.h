#include "SDL.h"
#include <map>
#include <string>

class layer
{
public:
    void addLayer(std::string destinationOfImage, int priority);
    void showLayers(SDL_Renderer *renderer);
private:
    std::map<int, SDL_Surface*> layers;
};
