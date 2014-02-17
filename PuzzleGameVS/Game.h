#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "State.h"
#include "Util.h"
#include "Background.h"
#include "stateManager.h"
#include "Board.h"
#include "layerManager.h"
#include "Player.h"
#include <queue>

class Game : public State
{
public:
	Game(SDL_Window *mainWindow, SDL_Renderer *passed_renderer, SDL_Surface *_windowSurface, std::string destinationOfImage, int bs);
	virtual ~Game();
	void start();
	void onMouseDown(int pointerX, int pointerY);
private:
	const int boardSize;
	Player* player1;
	Player* player2;
	Player* activePlayer;
	Board* board;
	SDL_Texture* backgroundTexture;
	ImgHolder* images;
	SDL_Surface *windowSurface;
	Layer *layerButton;
	Sprite *startGameButton;
	Background *backgroundSurface;
	global_States state;
	std::queue<int> damagePoints;
	bool isRunning;
	SDL_Renderer *renderer;
	SDL_Window *window;
	SDL_Event e;
private:
	void update();
	void handleDamage();
	void switchPlayer();
	void render();
	void dealDamage(Player *target, int amount);
	void checkPlayersState();
};

#endif //GAME_H