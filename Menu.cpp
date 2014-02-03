#include "Menu.h"

Menu::Menu(SDL_Surface *windowSurface, std::string destinationOfImage)
{
    backgroundSurface = new Background(windowSurface, destinationOfImage);

	layerButton = layerManager::addLayer(1);
	buttonSprite = new Sprite("red.bmp", 0, 100, 100, 100, 100);
	layerButton->addSprite(buttonSprite);
}

void Menu::onMouseDown(int pointerX, int pointerY)
{
	if (isPointInsideRectFromCorner(pointerX, pointerY, buttonSprite->mainRect))
	{
		
	}
}
