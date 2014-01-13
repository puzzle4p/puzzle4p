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
		/**
		 *  \brief Sprawdza (horyzontalnie) czy nowo dodawana kafelka może być umieszczona na danej pozycji
		 *  
		 *  \param [in] row Określa rząd w którym znajduje się kafelka którą chcemy dodać
		 *  \param [in] column Określa kolumnę w której znajduje się kafelka którą chcemy dodać
		 *  \return true - jeżeli kafelka nie tworzy w rzędzie 3 kafelek o takim samym kolorze, false - w przeciwnym przypadku
		 *  
		 *  \details Jako pomoc dla funkcji fillBoard()
		 */
		bool isValidTileHorizontal(int row, int column);
		/**
		 *  \brief Sprawdza (wertykalnie) czy nowo dodawana kafelka może być umieszczona na danej pozycji
		 *  
		 *  \param [in] row Określa rząd w którym znajduje się kafelka którą chcemy dodać
		 *  \param [in] column Określa kolumnę w której znajduje się kafelka którą chcemy dodać
		 *  \return true - jeżeli kafelka nie tworzy w kolumnie 3 kafelek o takim samym kolorze, false - w przeciwnym przypadku
		 *  
		 *  \details Jako pomoc dla funkcji fillBoard()
		 */
		bool isValidTileVertical(int row, int column);
		/**
		 *  \brief Sprawdza czy występują rzędy minimum 3 kafelek o takim samym kolorze.
		 *  
		 *  \details Jako pomoc dla funkcji checkIfMatch()
		 */
		void checkIfMatchHorizontal();
		/**
		 *  \brief Sprawdza czy występują kolumny minimum 3 kafelek o takim samym kolorze.
		 *  
		 *  \details Jako pomoc dla funkcji checkIfMatch()
		 */
		void checkIfMatchVertical();
		/**
		 *  \brief Usuwa kafelki przeznaczone do usunięcia
		 *  
		 */
		void destroyTiles();
		/**
		 *  \brief Sprawdza czy dwa kafelki sąsiadują ze sobą, a jeżeli tak to wywołuje funkcję changePlaceOfTiles()
		 *  
		 *  \param [in] row1 Rząd w którym znajduje się pierwszy kafelek
		 *  \param [in] column1 Kolumna w której znajduje się pierwszy kafelek
		 *  \param [in] row2 Rząd w którym znajduje się drugi kafelek
		 *  \param [in] column2 Kolumna w której znajduje się drugi kafelek
		 *  
		 */
		void tryToSwap(int row1, int column1, int row2, int column2);
		/**
		 *  \brief Zamienia ze sobą dwa kafelki
		 *  
		 *  \param [in] row Rząd w którym znajduje się kafelek
		 *  \param [in] column Kolumna w której znajduje się kafelek
		 *  \param [in] dir Kierunek w którym kafelek ma być przesunięty
		 *  
		 */
		void changePlaceOfTiles(int row, int column, direction dir);
		/**
		 *  \brief Wypełnia planszę kafelkami, pilnując żeby nie wystąpiły 3 takie same obok siebie
		 *  
		 */
		void fillBoard();
		/**
		 *  \brief Uzupełnia brakujące kafelki
		 *  
		 */
		void refillWithNewTiles();
		/**
		 *  \brief Wskazuje kalfelki do zniszczenia
		 *  
		 *  \return true - jeżeli są jakieś kafelki do zniszczenia, false - w przeciwnym przypadku
		 *  
		 */
		bool checkIfMatch();
		void update();
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
};
#endif