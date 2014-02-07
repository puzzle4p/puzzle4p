#include "Board.h"
#include <algorithm>
#include <iostream>
Board::Board(int _size, SDL_Surface* _targetSurface):
size(_size),
tiles(size, std::vector<Tile*>(size)),
tilesToDestroy(size, std::vector<bool>(size, false))
{
	tilesFactory = new TilesFactory();
	targetSurface = _targetSurface;
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
    bool validTile;
	for(int rowIndex = 0; rowIndex < size; rowIndex++)
	{
		for(int columnIndex = 0; columnIndex < size; columnIndex++)
		{
			do
			{
				tiles[rowIndex][columnIndex] = tilesFactory -> createTile();
				validTile = isValidTile(rowIndex, columnIndex);

				if(!validTile)
				{
					delete tiles[rowIndex][columnIndex];
					tiles[rowIndex][columnIndex] = NULL;
				}
			}
			while(!validTile);
		}
	}
}

bool Board::isValidTile(int row, int column)
{
    return (isValidTileHorizontal(row, column) && isValidTileVertical(row, column));
}

bool Board::isValidTileHorizontal(int row, int column)
{
    bool returnValue = true;
	if(column >= 2)
	{
		if(*(tiles[row][column]) == *(tiles[row][column - 1]))
        {
            if(*(tiles[row][column]) == *(tiles[row][column - 2]))
            {
                returnValue = false;
            }
        }
	}

	return returnValue;
}

bool Board::isValidTileVertical(int row, int column)
{
    bool returnValue = true;
	if(row >= 2)
	{
        if(*(tiles[row][column]) == *(tiles[row - 1][column]))
        {
            if(*(tiles[row][column]) == *(tiles[row - 2][column]))
            {
                returnValue = false;
            }
        }
	}

	return returnValue;
}
void Board::onMouseDown(SDL_Event event)
{
	if(event.type == SDL_MOUSEBUTTONDOWN)
	{
		int x = event.button.x;
		int y = event.button.y;
		Tile* clickedTile = NULL;

        clickedTile = whichTileHasBeenClicked(x, y);

		if(clickedTile != NULL)
		{
			if(previouslyClickedTile == NULL)
			{
				previouslyClickedTile = clickedTile;
				clickedTile = NULL;
			}
			else if(previouslyClickedTile != clickedTile)
			{
					tryToSwap(previouslyClickedTile, clickedTile);
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

Tile* Board::whichTileHasBeenClicked(int x, int y)
{
    Tile* clickedTile = NULL;

    for(int rowIndex = 0; rowIndex < size; rowIndex++)
    {
        for(int columnIndex = 0; columnIndex < size; columnIndex++)
        {
            if(x > tiles[rowIndex][columnIndex] -> getWidth() * rowIndex && x < (tiles[rowIndex][columnIndex] -> getWidth() * rowIndex) + tiles[rowIndex][columnIndex] -> getWidth())
            {
                if(y > tiles[rowIndex][columnIndex] -> getHeight() * columnIndex && y < (tiles[rowIndex][columnIndex] -> getHeight() * columnIndex) + tiles[rowIndex][columnIndex] -> getHeight())
                {
                    clickedTile = tiles[rowIndex][columnIndex];
                }
            }
        }
    }
    return clickedTile;
}

void Board::tryToSwap(Tile* firstTile, Tile* secondTile)
{
	direction dir;
	int row1, row2, column1, column2;
	findRowAndColumnIndex(firstTile, row1, column1);
	findRowAndColumnIndex(secondTile, row2, column2);
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

void Board::findRowAndColumnIndex(Tile* tile, int &destRow, int &destColumn)
{
    for (int rowIndex = 0; rowIndex < size; rowIndex++)
	{
		for(int columnIndex = 0; columnIndex < size; columnIndex++)
		{
			if(tile == tiles[rowIndex][columnIndex])
            {
                destRow = rowIndex;
                destColumn = columnIndex;
                break;
            }
		}
	}
}

void Board::changePlaceOfTiles(int row, int column, direction dir)
{
	switch(dir)
	{
		case up:
			moveTile(row, column, -1, 0);
			break;
		case down:
			moveTile(row, column, 1, 0);
			break;
		case left:
			moveTile(row, column, 0, -1);
			break;
		case right:
			moveTile(row, column, 0, 1);
			break;
	}
	if(!checkIfMatch())
	{
		switch(dir)
		{
			case up:
				moveTile(row, column, -1, 0);
				break;
			case down:
				moveTile(row, column, 1, 0);
				break;
			case left:
				moveTile(row, column, 0, -1);
				break;
			case right:
				moveTile(row, column, 0, 1);
				break;
		}
	}
}

void Board::moveTile(int row, int column, int deltaRow, int deltaColumn)
{
    std::swap(*tiles[row][column], *tiles[row + deltaRow][column + deltaColumn]);
}

void Board::update()
{
	if(anyMoreMoves())
	{
		checkIfMatch();
		destroyTiles();
        moveTilesDown();
		refillWithNewTiles();
	}
	else
	{
		//std::cout<<"No more moves\n";
		destroyAllTiles();
		fillBoard();
	}
	draw();
}

bool Board::checkIfMatch()
{
    bool returnValue = false;
	resetTilesToDestroy();
	checkIfMatchHorizontal();
	checkIfMatchVertical();
	for(int rowIndex = 0; rowIndex < size; rowIndex++)
	{
		for(int columnIndex = 0; columnIndex < size; columnIndex++)
		{
			if(tilesToDestroy[rowIndex][columnIndex])
			{
			    returnValue = true;
				break;
			}
		}
	}
	return returnValue;
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
			if(tilesToDestroy[rowIndex][columnIndex] && tiles[rowIndex][columnIndex] != NULL)
			{
                delete tiles[rowIndex][columnIndex];
                tiles[rowIndex][columnIndex] = NULL;
			}
		}
	}
}

void Board::refillWithNewTiles()
{
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
	return(anyMoreMovesHorizontal() || anyMoreMovesVertical());
}

bool Board::anyMoreMovesVertical()
{
    bool returnValue = false;
	int counter = 0;
	for(int columnIndex = 0; columnIndex < size; columnIndex++)
	{
		for(int rowIndex = 1; rowIndex < size; rowIndex++)
		{
			if(counter >= 2)
			{
				returnValue = true;
				break;
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
						returnValue = true;
                        break;
					}
					else if(rowIndex > 3 && *(tiles[rowIndex - 1][columnIndex]) == *(tiles[rowIndex - 4][columnIndex]))
					{
						returnValue = true;
                        break;
					}
				}
				counter = 0;
			}
		}
		counter = 0;
	}
	return returnValue;
}

bool Board::anyMoreMovesHorizontal()
{
    bool returnValue = false;
	int counter = 0;
	for(int rowIndex = 0; rowIndex < size; rowIndex++)
	{
		for(int columnIndex = 1; columnIndex < size; columnIndex++)
		{
			if(counter >= 2)
			{
				returnValue = true;
				break;
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
						returnValue = true;
                        break;
					}
					else if(columnIndex > 3 && *(tiles[rowIndex][columnIndex - 1]) == *(tiles[rowIndex][columnIndex - 4]))
					{
						returnValue = true;
                        break;
					}
				}
				counter = 0;
			}
		}
		counter = 0;
	}
	return returnValue;
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
void Board::draw()
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
