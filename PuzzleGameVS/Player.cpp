#include "Player.h"
#define MAX_HITPOINTS 100
#define HEALTH_BAR_H 10
Player::Player(SDL_Renderer *renderer, std::string name, std::string avatarPath)
{
	this->renderer = renderer;
    this -> name = name;
    this -> hitpoints = MAX_HITPOINTS;
	this->avatar = IMG_LoadTexture(renderer, avatarPath.c_str());
	SDL_QueryTexture(avatar, NULL, NULL, &avatar_width, &avatar_height);
    
}

Player::~Player()
{
    delete avatar;
}
void Player::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}
int Player::getWidth()
{
	return avatar_width * SIZE_MULTIPLER;
}
int Player::getHeight()
{
	return avatar_height * SIZE_MULTIPLER;
}
std::string Player::getName()
{
    return name;
}
void Player::dealDamage(int amount)
{
    hitpoints -= amount;
}
void Player::heal(int amount)
{
    hitpoints += amount;
}
bool Player::isAlive()
{
    return hitpoints > 0;
}
void Player::draw()
{
    SDL_Rect targetRect;
	targetRect.x = x;
	targetRect.y = y;
	targetRect.w = getWidth();
	targetRect.h = getHeight();
	SDL_Rect hpBar;
	hpBar.x = x;
	hpBar.y = y + getHeight();
	hpBar.w = (hitpoints * getWidth()) / MAX_HITPOINTS;
	hpBar.h = HEALTH_BAR_H;
	SDL_RenderCopy(renderer, avatar, NULL, &targetRect);
	if (hitpoints > 0)
	{
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &hpBar);
	}

}
void Player::drawActiveBar()
{
    SDL_Rect activeBar;
    activeBar.x = x;
	activeBar.y = y + getHeight() + HEALTH_BAR_H;
	activeBar.w = getWidth();
    activeBar.h = HEALTH_BAR_H;
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &activeBar);
}
