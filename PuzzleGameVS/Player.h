#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "SDL.h"
class Player
{
    private:
        std::string name;
        SDL_Surface* avatar;
        int hitpoints;
        int x, y;
    public:
        Player(std::string name, std::string avatarPath, int x, int y);
        virtual ~Player();
        std::string getName();
        void dealDamage(int amount);
        void heal(int amount);
        bool isAlive();
        void draw(SDL_Surface* target);
        void drawActiveBar(SDL_Surface* target);
};

#endif // PLAYER_H
