#include "Board.h"
#include <algorithm>
#include <iostream>

Board::Board() 
{
	tilesFactory = new TilesFactory();
	previouslyClickedTile = NULL;
	for (int i = 0; i < 8; i++) 
	{
		for(int j = 0; j < 8; j++)
		{
			tilesToDestroy[i][j] = false;
		}
	}
	fillBoard();
	std::cout<<"TestB\n";
	boardSurface = SDL_LoadBMP("Images\\board.bmp");
	std::cout<<"TestB\n";
}

Board::~Board() 
{
	delete tilesFactory;
	for (int i = 0; i < 8; i++) 
	{
		for(int j = 0; j < 8; j++)
		{
			delete tiles[i][j];
		}
	}
}

void Board::fillBoard() 
{
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			bool isValidTile;
			do
			{
				isValidTile = true;
				tiles[i][j] = tilesFactory -> createTile();
				if(!isValidTileHorizontal(i, j))
				{
					isValidTile = false;
				}
				else if(!isValidTileVertical(i, j))
				{
					isValidTile = false;
				}
				if(!isValidTile)
				{
					delete tiles[i][j];
					tiles[i][j] = NULL;
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
	std::cout<<tiles[row][column] -> color<<" "<<tiles[row][column - 1] -> color<<" "<<tiles[row][column - 2] -> color<<"\n";
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
		int previouslyClickedTileX;
		int previouslyClickedTileY;
		int clickedTileX;
		int clickedTileY;
		
		for(int i = 0; i < 8; i++)
		{
			for(int j = 0; j < 8; j++)
			{
				if(x > tiles[i][j] -> getWidth() * i && x < (tiles[i][j] -> getWidth() * i) + tiles[i][j] -> getWidth())
				{
					if(y > tiles[i][j] -> getHeight() * j && y < (tiles[i][j] -> getHeight() * j) + tiles[i][j] -> getHeight())
					{
						clickedTile = tiles[i][j];
						clickedTileX = j;
						clickedTileY = i;
					}
				}
				if(previouslyClickedTile != NULL)
				{
					if(previouslyClickedTile == tiles[i][j])
					{
						previouslyClickedTileX = j;
						previouslyClickedTileY = i;
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
			else
			{
				if(previouslyClickedTile != clickedTile)
				{
					tryToSwap(previouslyClickedTileX, previouslyClickedTileY, clickedTileX, clickedTileY);
					previouslyClickedTile = NULL;
					clickedTile = NULL;
				}
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
	if(dir == up)
	{
		if(row != 0)
		{
			std::swap(tiles[row][column], tiles[row - 1][column]);
		}
	}
	else if(dir == down)
	{	
		if(row == 7)
		{
			std::swap(tiles[row][column], tiles[row + 1][column]);
		}
	}
	else if(dir == left)
	{
		if(column == 0)
		{
			std::swap(tiles[row][column], tiles[row][column - 1]);
		}
	}
	else if(dir == right)
	{
		if(column == 7)
		{
			std::swap(tiles[row][column], tiles[row][column + 1]);
		}
	}
	update();	

}

void Board::update() 
{
	if(checkIfMatch())
	{
		destroyTiles();
		refillWithNewTiles();
	}
}

bool Board::checkIfMatch() 
{
	checkIfMatchHorizontal();
	checkIfMatchVertical();
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			if(tilesToDestroy[i][j])
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
	for(int i = 0; i < 8; i++)
	{
		for(int j = 1; j < 8; j++)
		{
			if(*(tiles[i][j]) == *(tiles[i][j - 1]))
			{
				count++;
			}
			else
			{
				if(count >= 2)
				{
					for (int k = count; k >= 0; k--)
					{
						tilesToDestroy[i][j - 1 - count] = true;
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
	for(int i = 1; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			if(*(tiles[i][j]) == *(tiles[i - 1][j]))
			{
				count++;
			}
			else
			{
				if(count >= 2)
				{
					for (int k = count; k >= 0; k--)
					{
						tilesToDestroy[i - 1 - count][j] = true;
					}
				}
				count = 0;
			}
		}
	}
}

void Board::destroyTiles() 
{
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			if(tilesToDestroy[i][j])
			{
				delete tiles[i][j];
				tiles[i][j] = NULL;
				tilesToDestroy[i][j] = false;
			}
		}
	}
}

void Board::refillWithNewTiles() 
{
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			if(tiles[i][j] == NULL)
			{
				tiles[i][j] = tilesFactory -> createTile();
			}
		}
	}
	update();
}

void Board::draw(SDL_Surface* targetSurface) 
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			tiles[i][j] -> draw(boardSurface, tiles[i][j] -> getWidth() * i, tiles[i][j] -> getHeight() * j);
		}
	}
	SDL_BlitSurface(boardSurface, NULL, targetSurface, NULL);
}