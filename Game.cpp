#include "Game.h"
#include <iostream>
const int boardPlacementX = 65;
const int boardPlacementY = 130;
Game::Game(SDL_Window* window, int bs):
    boardSize(bs)
{
    this -> window = window;
    windowSurface = SDL_GetWindowSurface(window);
    board = new Board(bs, windowSurface, boardPlacementX, boardPlacementY, damagePoints);
    player1 = new Player("Player 1", "Images//player1.bmp", 0, 0);
    player2 = new Player("Player 2", "Images//player2.bmp", windowSurface -> w - 60, 0);
    activePlayer = player1;
    isRunning = false;
}

Game::~Game()
{
    delete board;
    delete player1;
    delete player2;
}
void Game::start()
{
    isRunning = true;
    update();
}
void Game::update()
{
    while(isRunning)
    {
        board -> update();
        checkPlayersState();
        if(!damagePoints.empty())
        {
            handleDamage();
            switchPlayer();
        }
        handleInput();
        render();
    }
}
void Game::handleInput()
{
    while(SDL_PollEvent(&e))
    {
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            board -> onMouseDown(e.button.x - boardPlacementX, e.button.y - boardPlacementY);
        }
        else if(e.type == SDL_QUIT)
        {
            isRunning = false;
        }
    }
}
void Game::handleDamage()
{
    while(!damagePoints.empty())
    {
        if(activePlayer == player1)
        {
            dealDamage(player2, damagePoints.front());
        }
        else
        {
            dealDamage(player1, damagePoints.front());
        }
        damagePoints.pop();
    }
}
void Game::switchPlayer()
{
    if(activePlayer == player1)
    {
        activePlayer = player2;
    }
    else
    {
        activePlayer = player1;
    }
}
void Game::render()
{
    SDL_Rect background;
	background.x = 0;
	background.y = 0;
	background.w = windowSurface -> w;
	background.h = windowSurface -> h;
	SDL_FillRect(windowSurface, &background, SDL_MapRGB(windowSurface -> format, 0, 0, 127));
    board -> draw();
    activePlayer -> drawActiveBar(windowSurface);
    player1 -> draw(windowSurface);
    player2 -> draw(windowSurface);
    SDL_UpdateWindowSurface(window);
}
void Game::dealDamage(Player *target, int amount)
{
    target -> dealDamage(amount);
    //std::cout<<"Zadano "<<amount<<" obrazen, graczowi "<<target->getName()<<std::endl;
}
void Game::checkPlayersState()
{
    isRunning = (player1 -> isAlive() && player2 -> isAlive());
}
