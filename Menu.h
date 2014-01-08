#include <string>

class Menu
{
public:
    Menu(SDL_Window *mainWindow, std::string destinationOfImage);
    ~Menu();
    void onMouseDown(SDL_Event event, int pointerX, int pointerY);
private:
    SDL_Surface *windowSurface;
    SDL_Surface *backgroundSurface;
};
