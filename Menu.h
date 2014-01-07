#include <string>

class Menu
{
public:
    Menu(SDL_Window *mainWindow, std::string destinationOfImage);
    ~Menu();
    bool onMouseClick(SDL_Event event);
private:
    SDL_Surface *windowSurface;
    SDL_Surface *backgroundSurface;
};
