#ifndef BOARD_H
#define BOARD_H
#include <SDL.h>
#include <vector>
#include <queue>
#include "Tile.h"
#include "TilesFactory.h"
#include "Direction.h"
/**
 *  \file Board.h
 *  \brief Plansza do gry typu Puzzle Quest
 */
class Board
{
	private:
		const int size;
		std::vector<std::vector<Tile*> > tiles;
		TilesFactory* tilesFactory;
		std::vector<std::vector<bool> > tilesToDestroy;
		Tile* previouslyClickedTile;
		SDL_Surface* boardSurface;
		SDL_Surface* targetSurface;
		int x, y;
		std::queue<int>* damagePoints;
	private:
	    bool isValidTile(int row, int column);
		bool isValidTileHorizontal(int row, int column);
		bool isValidTileVertical(int row, int column);
		void checkIfMatchHorizontal();
		void checkIfMatchVertical();
		void destroyTiles();
		void tryToSwap(Tile* firstTile, Tile* secondTile);
		void changePlaceOfTiles(int row, int column, direction dir);
		Tile* whichTileHasBeenClicked(int x, int y);
		void findRowAndColumnIndex(Tile* tile, int &destRow, int &destColumn);
		void moveTile(int row, int column, int deltaRow, int deltaColumn);
		void fillBoard();
		void refillWithNewTiles();
		void moveTilesDown();
		bool checkIfMatch();
		void resetTilesToDestroy();
		bool anyMoreMoves();
		bool anyMoreMovesVertical();
		bool anyMoreMovesHorizontal();
		void destroyAllTiles();
	public:
		Board(int _size, SDL_Surface* _targetSurface, int _x, int _y, std::queue<int> &damageQueue);
		~Board();
		/**
		 *  \brief Obsługuje kliknięcia myszą na kafelkach.
		 *
		 *  \param [in] event - SDL_Event
		 *
		 *  \details Należy wywoływać z klasy sprawującej kontrolę nad zdarzeniami SDL
		 */
		void onMouseDown(int posX, int posY);
		/**
		 *  \brief Rysuje plansze do  gry wraz z kafelkami
		 *
		 *  \param [in] targetSurface Powierzchnia na której ma być narysowana plansza
		 *
		 */
		void draw();
		void update();
};
#endif
