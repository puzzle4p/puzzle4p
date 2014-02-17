#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#define SIZE_MULTIPLER 0.72
class Player
{
    private:
        std::string name;
        SDL_Texture* avatar;
        int hitpoints;
        int x, y, avatar_width, avatar_height;
		SDL_Renderer *renderer;
    public:
        Player(SDL_Renderer *renderer, std::string name, std::string avatarPath);
        virtual ~Player();
        std::string getName();
		void setPosition(int x, int y);
		int getWidth();
		int getHeight();
        void dealDamage(int amount);
        void heal(int amount);
        bool isAlive();
        void draw();
        void drawActiveBar();
};

#endif // PLAYER_H
