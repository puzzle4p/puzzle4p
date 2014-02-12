#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
#include "Board.h"
#include "Player.h"
class Game
{
    private:
        const int boardSize;
        Player* player1;
        Player* player2;
        Board* board;
        SDL_Window* window;
        SDL_Surface* windowSurface;
        SDL_Event e;
        bool isRunning;

    private:
        void update();
        void handleInput();
        void render();
        void dealDamage(Player &target, int amount);
    public:
        Game(SDL_Window* window, int bs);
        virtual ~Game();
        void start();
};

#endif // GAME_H
