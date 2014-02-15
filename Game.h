#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
#include <queue>
#include "Board.h"
#include "Player.h"
class Game
{
    private:
        const int boardSize;
        Player* player1;
        Player* player2;
        Player* activePlayer;
        Board* board;
        SDL_Window* window;
        SDL_Surface* windowSurface;
        SDL_Event e;
        bool isRunning;
        std::queue<int> damagePoints;
    private:
        void update();
        void handleInput();
        void handleDamage();
        void switchPlayer();
        void render();
        void dealDamage(Player *target, int amount);
        void checkPlayersState();
    public:
        Game(SDL_Window* window, int bs);
        virtual ~Game();
        void start();
};

#endif // GAME_H
