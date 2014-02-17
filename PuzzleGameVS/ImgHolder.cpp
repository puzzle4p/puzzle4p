#include "ImgHolder.h"
ImgHolder::ImgHolder(SDL_Renderer *renderer)
{
	
	images.push_back(IMG_LoadTexture(renderer, "Images///Gems//Gem_Blue_1.png"));
	images.push_back(IMG_LoadTexture(renderer, "Images//Gems//Gem_Green_1.png"));
	images.push_back(IMG_LoadTexture(renderer, "Images//Gems//Gem_Purple_1.png"));
	images.push_back(IMG_LoadTexture(renderer, "Images//Gems//Gem_Red_1.png"));
	images.push_back(IMG_LoadTexture(renderer, "Images//Gems//Gem_Yellow_1.png"));

	images.push_back(IMG_LoadTexture(renderer, "Images//Gems//Gem_Blue_2.png"));
	images.push_back(IMG_LoadTexture(renderer, "Images//Gems//Gem_Green_2.png"));
	images.push_back(IMG_LoadTexture(renderer, "Images//Gems//Gem_Purple_2.png"));
	images.push_back(IMG_LoadTexture(renderer, "Images//Gems//Gem_Red_2.png"));
	images.push_back(IMG_LoadTexture(renderer, "Images//Gems//Gem_Yellow_2.png"));
}
SDL_Texture* ImgHolder::getImage(int color)
{
	return images[color];
}