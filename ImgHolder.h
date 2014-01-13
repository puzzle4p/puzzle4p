#ifndef IMGHOLDER_H
#define IMGHOLDER_H
#include <SDL.h>
#include <vector>
#include "Colors.h"

class ImgHolder 
{
	private:
		std::vector<SDL_Surface*> images;
	public:
		ImgHolder();
		SDL_Surface* getImage(Color color);
};

#endif