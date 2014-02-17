#ifndef IMGHOLDER_H
#define IMGHOLDER_H
#include <SDL.h>
#include <vector>
#include "Colors.h"
#include "SDL_image.h"

class ImgHolder 
{
	private:
		std::vector<SDL_Texture*> images;
	public:
		ImgHolder(SDL_Renderer *renderer);
		SDL_Texture* getImage(int color);
};

#endif