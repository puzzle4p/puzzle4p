#include "Player.h"
#define MAX_HITPOINTS 100
#define HEALTH_BAR_H 10
Player::Player(std::string name, std::string avatarPath, int x, int y)
{
    this -> name = name;
    this -> hitpoints = MAX_HITPOINTS;
    this -> avatar = SDL_LoadBMP(avatarPath.c_str());
    this -> x = x;
    this -> y = y;
}

Player::~Player()
{
    delete avatar;
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
void Player::draw(SDL_Surface* target)
{
    SDL_Rect targetRect;
	targetRect.x = x;
	targetRect.y = y;
	SDL_Rect hpBar;
	hpBar.x = x;
	hpBar.y = y + avatar -> h;
	hpBar.w = (hitpoints * avatar -> w) / MAX_HITPOINTS;
	hpBar.h = HEALTH_BAR_H;
	SDL_FillRect(target, &hpBar, SDL_MapRGB(target->format, 255, 0, 0));
    SDL_BlitSurface(avatar, NULL, target, &targetRect);
}
void Player::drawActiveBar(SDL_Surface* target)
{
    SDL_Rect activeBar;
    activeBar.x = x;
    activeBar.y = y + avatar -> h + HEALTH_BAR_H;
    activeBar.w = avatar -> w;
    activeBar.h = HEALTH_BAR_H;
    SDL_FillRect(target, &activeBar, SDL_MapRGB(target -> format, 255, 255, 255));
}
