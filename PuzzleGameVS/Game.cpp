#include "Game.h"

const int boardPlacementX = 365;
const int boardPlacementY = 20;

Game::Game(SDL_Window *mainWindow, SDL_Renderer *passed_renderer, SDL_Surface *_windowSurface, std::string destinationOfImage, int bs) : boardSize(bs)
{
	renderer = passed_renderer;
	window = mainWindow;
	windowSurface = _windowSurface;
	images = new ImgHolder(renderer);
	backgroundTexture = IMG_LoadTexture(renderer, "Images//Background.bmp");
	board = new Board(bs, images, renderer, windowSurface, boardPlacementX, boardPlacementY, damagePoints);
	player1 = new Player(renderer, "Player 1", "Images//Character_1.png");
	player2 = new Player(renderer, "Player 2", "Images//Character_2.png");
	player1->setPosition(11, 0);
	player2->setPosition(windowSurface->w - player2->getWidth() - 11, 0);
	activePlayer = player1;
	isRunning = false;
	start();
}

Game::~Game()
{
	delete images;
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
	board->update();
	if (!damagePoints.empty())
	{
		handleDamage();
		switchPlayer();
	}
	checkPlayersState();
	render();
}

void Game::onMouseDown(int pointerX, int pointerY)
{
	if (isPointInsideRectFromMiddle(pointerX, pointerY, 0, 0, 100, 100))
	{
		stateManager::changeState(STATE_MENU);
	}
	board->onMouseDown(pointerX - boardPlacementX, pointerY - boardPlacementY);
}
void Game::handleDamage()
{
	while (!damagePoints.empty())
	{
		if (activePlayer == player1)
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
	if (activePlayer == player1)
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
	background.w = windowSurface->w;
	background.h = windowSurface->h;
	//SDL_QueryTexture(backgroundTexture, NULL, NULL, &background.w, &background.h);
	//SDL_SetRenderDrawColor(renderer, 0, 0, 127, 255);
	//SDL_RenderFillRect(renderer, &background);
	SDL_RenderCopy(renderer, backgroundTexture, NULL, &background);
	board->draw();
	activePlayer->drawActiveBar();
	player1->draw();
	player2->draw();
	SDL_RenderPresent(renderer);
}
void Game::dealDamage(Player *target, int amount)
{
	target->dealDamage(amount);
	//std::cout<<"Zadano "<<amount<<" obrazen, graczowi "<<target->getName()<<std::endl;
}
void Game::checkPlayersState()
{
	if (!(player1->isAlive() && player2->isAlive()))
	{
		stateManager::changeState(STATE_MENU);
	}
}
