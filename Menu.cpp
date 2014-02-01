#include "Menu.h"

Menu::Menu(SDL_Surface *windowSurface, std::string destinationOfImage)
{
    backgroundSurface = new Background(windowSurface, destinationOfImage);
	layerManager::layers[1]->addSprite(new Sprite("red.bmp", 0, 100, 100, 100, 100));
	b = new Button(100, 100, 100, 100);
}

void Menu::onMouseDown(int pointerX, int pointerY)
{
	if (isPointInsideRectFromCorner(pointerX, pointerY, b->rect))
	{
		
	}
}
