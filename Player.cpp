#include "Player.h"

Player::Player(std::string name)
{
    //ctor
}

Player::~Player()
{
    //dtor
}
void Player::dealDamage(int amount)
{
    hitpoints -= amount;
}
