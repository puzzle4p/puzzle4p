#include <string>

class Menu
{
public:
    Menu(SDL_Window *mainWindow, std::string destinationOfImage);
    ~Menu();
    void onMouseClick(SDL_Event event);
private:
    SDL_Surface *windowSurface;
    SDL_Surface *backgroundSurface;
};
