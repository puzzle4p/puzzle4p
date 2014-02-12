#include "Game.h"

Game::Game(SDL_Window* window, int bs):
    boardSize(bs)
{
    this -> window = window;
    windowSurface = SDL_GetWindowSurface(window);
    board = new Board(bs, windowSurface);
    player1 = new Player("Player 1");
    player2 = new Player("Player 2");
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
            board -> onMouseDown(e);
        }
        else if(e.type == SDL_QUIT)
        {
            isRunning = false;
        }
    }
}
void Game::render()
{
    board -> draw();
    SDL_UpdateWindowSurface(window);
}
void Game::dealDamage(Player &target, int amount)
{
    //bedzie pozniej
}
