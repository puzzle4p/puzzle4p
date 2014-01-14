#ifndef BOARD_H
#define BOARD_H
#include <SDL.h>
#include "Tile.h"
#include "TilesFactory.h"
/**
 *  \file Board.h
 *  \brief Plansza do gry typu Puzzle Quest
 */
class Board 
{
	private:
		Tile* tiles[8][8];
		TilesFactory* tilesFactory;
		bool tilesToDestroy[8][8];
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
		void fillBoard();
		void refillWithNewTiles();
		bool checkIfMatch();
		void resetTilesToDestroy();
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