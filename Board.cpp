#include "Board.h"
#include <algorithm>
#include <iostream>
Board::Board(int _size):
size(_size),
tiles(size, std::vector<Tile*>(size)),
tilesToDestroy(size, std::vector<bool>(size, false))
{
	tilesFactory = new TilesFactory();
	previouslyClickedTile = NULL;
	fillBoard();
	boardSurface = SDL_CreateRGBSurface(0, size * 60, size * 60, 32, 0, 0, 0, 0);

}

Board::~Board() 
{
	delete tilesFactory;
	for (int rowIndex = 0; rowIndex < size; rowIndex++) 
	{
		for(int columnIndex = 0; columnIndex < size; columnIndex++)
		{
			delete tiles[rowIndex][columnIndex];
		}
	}
}

void Board::fillBoard() 
{
	for(int rowIndex = 0; rowIndex < size; rowIndex++)
	{
		for(int columnIndex = 0; columnIndex < size; columnIndex++)
		{
			bool isValidTile;
			do
			{
				isValidTile = true;
				tiles[rowIndex][columnIndex] = tilesFactory -> createTile();
				if(!isValidTileHorizontal(rowIndex, columnIndex))
				{
					isValidTile = false;
				}
				else if(!isValidTileVertical(rowIndex, columnIndex))
				{
					isValidTile = false;
				}
				if(!isValidTile)
				{
					delete tiles[rowIndex][columnIndex];
					tiles[rowIndex][columnIndex] = NULL;
				}
			}
			while(!isValidTile);
		}
	}
	
}

bool Board::isValidTileHorizontal(int row, int column) 
{
	if(column < 2)
	{
		return true;
	}
	if(*(tiles[row][column]) == *(tiles[row][column - 1]))
	{
		if(*(tiles[row][column]) == *(tiles[row][column - 2]))
		{
			return false;
		}
	}
	return true;	
}

bool Board::isValidTileVertical(int row, int column) 
{
	if(row < 2)
	{
		return true;
	}
	if(*(tiles[row][column]) == *(tiles[row - 1][column]))
	{
		if(*(tiles[row][column]) == *(tiles[row - 2][column]))
		{
			return false;
		}
	}
	return true;
}

void Board::onMouseDown(SDL_Event event) 
{
	if(event.type == SDL_MOUSEBUTTONDOWN)
	{
		int x = event.button.x;
		int y = event.button.y;
		Tile* clickedTile = NULL;
		int previouslyClickedTileRow;
		int previouslyClickedTileColumn;
		int clickedTileRow;
		int clickedTileColumn;
		
		for(int rowIndex = 0; rowIndex < size; rowIndex++)
		{
			for(int columnIndex = 0; columnIndex < size; columnIndex++)
			{
				if(x > tiles[rowIndex][columnIndex] -> getWidth() * rowIndex && x < (tiles[rowIndex][columnIndex] -> getWidth() * rowIndex) + tiles[rowIndex][columnIndex] -> getWidth())
				{
					if(y > tiles[rowIndex][columnIndex] -> getHeight() * columnIndex && y < (tiles[rowIndex][columnIndex] -> getHeight() * columnIndex) + tiles[rowIndex][columnIndex] -> getHeight())
					{
						clickedTile = tiles[rowIndex][columnIndex];
						clickedTileRow = rowIndex;
						clickedTileColumn = columnIndex;
					}
				}
				if(previouslyClickedTile != NULL)
				{
					if(previouslyClickedTile == tiles[rowIndex][columnIndex])
					{
						previouslyClickedTileRow = rowIndex;
						previouslyClickedTileColumn = columnIndex;
					}
				}
			}
		}
		
		if(clickedTile != NULL)
		{
			if(previouslyClickedTile == NULL)
			{
				previouslyClickedTile = clickedTile;
				clickedTile = NULL;
			}
			else if(previouslyClickedTile != clickedTile)
			{
					tryToSwap(previouslyClickedTileRow, previouslyClickedTileColumn, clickedTileRow, clickedTileColumn);
					previouslyClickedTile = NULL;
					clickedTile = NULL;
			}
			else
			{
				previouslyClickedTile = NULL;
			}
		}
		else 
		{
			previouslyClickedTile = NULL;
		}
	}
}

void Board::tryToSwap(int row1, int column1, int row2, int column2) 
{
	direction dir;
	if(row1 == row2 + 1 && column1 == column2)
	{
		dir = up;
		changePlaceOfTiles(row1, column1, dir);
	}
	else if(row1 == row2 - 1 && column1 == column2)
	{
		dir = down;
		changePlaceOfTiles(row1, column1, dir);
	}
	else if(row1 == row2 && column1 == column2 + 1)
	{
		dir = left;
		changePlaceOfTiles(row1, column1, dir);
	}
	else if(row1 == row2 && column1 == column2 - 1)
	{
		dir = right;
		changePlaceOfTiles(row1, column1, dir);
	}
}

void Board::changePlaceOfTiles(int row, int column, direction dir) 
{
	switch(dir)
	{
		case up:
			moveTileUp(row, column);
			break;
		case down:
			moveTileDown(row, column);
			break;
		case left:
			moveTileLeft(row, column);
			break;
		case right:
			moveTileRight(row, column);
			break;
	}
	if(!checkIfMatch())
	{
		switch(dir)
		{
			case up:
				moveTileUp(row, column);
				break;
			case down:
				moveTileDown(row, column);
				break;
			case left:
				moveTileLeft(row, column);
				break;
			case right:
				moveTileRight(row, column);
				break;
		}
	}
}

void Board::moveTileUp(int row, int column)
{
	if(row > 0)
	{
		std::swap(tiles[row][column], tiles[row - 1][column]);
	}
}

void Board::moveTileDown(int row, int column)
{
	if(row < size - 1)
	{
		std::swap(tiles[row][column], tiles[row + 1][column]);
	}
}

void Board::moveTileLeft(int row, int column)
{
	if(column > 0)
	{
		std::swap(tiles[row][column], tiles[row][column - 1]);
	}
}

void Board::moveTileRight(int row, int column)
{
	if(column < size - 1)
	{
		std::swap(tiles[row][column], tiles[row][column + 1]);
	}
}

void Board::update() 
{
	if(anyMoreMoves())
	{
		checkIfMatch();
		destroyTiles();
		refillWithNewTiles();
	}
	else
	{
		//std::cout<<"No more moves\n";
		destroyAllTiles();
		fillBoard();
	}
}

bool Board::checkIfMatch() 
{
	resetTilesToDestroy();
	checkIfMatchHorizontal();
	checkIfMatchVertical();
	for(int rowIndex = 0; rowIndex < size; rowIndex++)
	{
		for(int columnIndex = 0; columnIndex < size; columnIndex++)
		{
			if(tilesToDestroy[rowIndex][columnIndex])
			{
				return true;
			}
		}
	}
	return false;
}

void Board::checkIfMatchHorizontal() 
{
	int count = 0;
	for(int rowIndex = 0; rowIndex < size; rowIndex++)
	{
		for(int columnIndex = 1; columnIndex < size; columnIndex++)
		{
			if(*(tiles[rowIndex][columnIndex]) == *(tiles[rowIndex][columnIndex - 1]) && columnIndex != size - 1)
			{
				count++;
			}
			else if(*(tiles[rowIndex][columnIndex]) == *(tiles[rowIndex][columnIndex - 1]) && columnIndex == size - 1)
			{
				count++;
				if(count >= 2)
				{
					for (int k = count; k >= 0; k--)
					{
						tilesToDestroy[rowIndex][columnIndex - k] = true;
					}
				}
				count = 0;
			}
			else
			{
				if(count >= 2)
				{
					for (int k = count; k >= 0; k--)
					{
						tilesToDestroy[rowIndex][columnIndex - 1 - k] = true;
					}
				}
				count = 0;
			}
		}
	}
}
	
void Board::checkIfMatchVertical() 
{
	int count = 0;
	for(int columnIndex = 0; columnIndex < size; columnIndex++)
	{
		for(int rowIndex = 1; rowIndex < size; rowIndex++)
		{
			if(*(tiles[rowIndex][columnIndex]) == *(tiles[rowIndex - 1][columnIndex]) && rowIndex != size - 1)
			{
				count++;
			}
			else if(*(tiles[rowIndex][columnIndex]) == *(tiles[rowIndex - 1][columnIndex]) && rowIndex == size - 1)
			{
				count++;
				if(count >= 2)
				{
					for (int k = count; k >= 0; k--)
					{
						tilesToDestroy[rowIndex - k][columnIndex] = true;
					}
				}
				count = 0;
			}
			else
			{
				if(count >= 2)
				{
					for (int k = count; k >= 0; k--)
					{
						tilesToDestroy[rowIndex - 1 - k][columnIndex] = true;
					}
				}
				count = 0;
			}
		}
		
	}
}

void Board::destroyTiles() 
{
	for(int rowIndex = 0; rowIndex < size; rowIndex++)
	{
		for(int columnIndex = 0; columnIndex < size; columnIndex++)
		{
			if(tilesToDestroy[rowIndex][columnIndex])
			{
				if(tiles[rowIndex][columnIndex] != NULL)
				{
					delete tiles[rowIndex][columnIndex];
					tiles[rowIndex][columnIndex] = NULL;
				}
			}
		}
	}
}

void Board::refillWithNewTiles() 
{
	moveTilesDown();
	for(int rowIndex = 0; rowIndex < size; rowIndex++)
	{
		for(int columnIndex = 0; columnIndex < size; columnIndex++)
		{
			if(tiles[rowIndex][columnIndex] == NULL)
			{
				tiles[rowIndex][columnIndex] = tilesFactory -> createTile();
				
			}
		}
	}
}

void Board::moveTilesDown()
{
	for(int rowIndex = 0; rowIndex < size; rowIndex++)
	{
		for(int columnIndex = 0; columnIndex < size; columnIndex++)
		{
			if(tiles[rowIndex][columnIndex] == NULL)
			{
				for(int k = columnIndex; k > 0; k--)
				{
					std::swap(tiles[rowIndex][k], tiles[rowIndex][k - 1]);
				}
				
			}
		}
	}
}

bool Board::anyMoreMoves()
{
	if(anyMoreMovesVertical())
	{
		return true;
	}
	else if(anyMoreMovesHorizontal())
	{
		return true;
	}
	return false;
}

bool Board::anyMoreMovesVertical()
{
	int counter = 0;
	for(int columnIndex = 0; columnIndex < size; columnIndex++)
	{
		for(int rowIndex = 1; rowIndex < size; rowIndex++)
		{
			if(counter >= 2)
			{
				return true;
			}
			if(*(tiles[rowIndex][columnIndex]) == *(tiles[rowIndex - 1][columnIndex]))
			{
				counter++;
			}
			else
			{
				if(counter >= 1)
				{
					if(rowIndex < size - 1 && *(tiles[rowIndex - 1][columnIndex]) == *(tiles[rowIndex + 1][columnIndex]))
					{
						return true;
					}
					else if(rowIndex > 3 && *(tiles[rowIndex - 1][columnIndex]) == *(tiles[rowIndex - 4][columnIndex]))
					{
						return true;
					}
				}
				counter = 0;
			}
		}
		counter = 0;
	}
	return false;
}

bool Board::anyMoreMovesHorizontal()
{
	int counter = 0;
	for(int rowIndex = 0; rowIndex < size; rowIndex++)	
	{
		for(int columnIndex = 1; columnIndex < size; columnIndex++)
		{
			if(counter >= 2)
			{
				return true;
			}
			if(*(tiles[rowIndex][columnIndex]) == *(tiles[rowIndex][columnIndex - 1]))
			{
				counter++;
			}
			else
			{
				if(counter >= 1)
				{
					if(columnIndex < size - 1 && *(tiles[rowIndex][columnIndex - 1]) == *(tiles[rowIndex][columnIndex + 1]))
					{
						return true;
					}
					else if(columnIndex > 3 && *(tiles[rowIndex][columnIndex - 1]) == *(tiles[rowIndex][columnIndex - 4]))
					{
						return true;
					}
				}
				counter = 0;
			}
		}
		counter = 0;
	}
	return false;
}

void Board::destroyAllTiles()
{
	for (int rowIndex = 0; rowIndex < size; rowIndex++) 
	{
		for(int columnIndex = 0; columnIndex < size; columnIndex++)
		{
			if(tiles[rowIndex][columnIndex] != NULL)
			{
				delete tiles[rowIndex][columnIndex];
				tiles[rowIndex][columnIndex] = NULL;
			}
		}
	}
}

void Board::resetTilesToDestroy()
{
	for(int rowIndex = 0; rowIndex < size; rowIndex++)
	{
		for(int columnIndex = 0; columnIndex < size; columnIndex++)
		{
			tilesToDestroy[rowIndex][columnIndex] = false;
		}
	}
}
void Board::draw(SDL_Surface* targetSurface) 
{
	SDL_Rect background;
	background.x = 0;
	background.y = 0;
	background.w = size * 60;
	background.h = size * 60;
	SDL_FillRect(boardSurface, &background, 0);

	if(previouslyClickedTile != NULL)
	{
		previouslyClickedTile -> setHighlight(true);
	}
	for (int rowIndex = 0; rowIndex < size; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < size; columnIndex++)
		{
			if(tiles[rowIndex][columnIndex] != NULL)
			{
				tiles[rowIndex][columnIndex] -> draw(boardSurface, tiles[rowIndex][columnIndex] -> getWidth() * rowIndex, tiles[rowIndex][columnIndex] -> getHeight() * columnIndex);
			}
		}
	}
	SDL_BlitSurface(boardSurface, NULL, targetSurface, NULL);
	if(previouslyClickedTile != NULL)
	{
		previouslyClickedTile -> setHighlight(false);
	}
}