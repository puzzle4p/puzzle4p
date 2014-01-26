#ifndef BOARD_H
#define BOARD_H
#include <SDL.h>
#include <vector>
#include "Tile.h"
#include "TilesFactory.h"
/**
 *  \file Board.h
 *  \brief Plansza do gry typu Puzzle Quest
 */
class Board 
{
	private:
		std::vector<std::vector<Tile*> > tiles;
		TilesFactory* tilesFactory;
		std::vector<std::vector<bool> > tilesToDestroy;
		Tile* previouslyClickedTile;
		enum direction {up, down, left, right};
		SDL_Surface* boardSurface;
	private:
		bool isValidTileHorizontal(int row, int column);
		bool isValidTileVertical(int row, int column);
		void checkIfMatchHorizontal();
		void checkIfMatchVertical();
		void destroyTiles();
		void tryToSwap(int row1, int column1, int row2, int column2);
		void changePlaceOfTiles(int row, int column, direction dir);
		void moveTileUp(int row, int column);
		void moveTileDown(int row, int column);
		void moveTileLeft(int row, int column);
		void moveTileRight(int row, int column);
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
		Board();
		~Board();
		/**
		 *  \brief Obsługuje kliknięcia myszą na kafelkach.
		 *  
		 *  \param [in] event - SDL_Event
		 *  
		 *  \details Należy wywoływać z klasy sprawującej kontrolę nad zdarzeniami SDL
		 */
		void onMouseDown(SDL_Event event);
		/**
		 *  \brief Rysuje plansze do  gry wraz z kafelkami
		 *  
		 *  \param [in] targetSurface Powierzchnia na której ma być narysowana plansza
		 *  
		 */
		void draw(SDL_Surface* targetSurface);
		void update();
};
#endif