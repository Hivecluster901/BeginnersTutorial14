#include "Board.h"
#include <assert.h>

Board::Board(Graphics& gfx)
	:
	gfx(gfx)
{
}

void Board::DrawCell( const Location& loc, Color c)
{
	
	gfx.DrawRectDim(loc.x * dimension, loc.y * dimension, dimension, dimension, c);

}

int Board::GetGridWidth() const
{
	return width;
}

int Board::GetGridHeight() const
{
	return height;
}

bool Board::isWithinBoard(const Location& loc)
{
	return loc.x >= 0 && loc.y >= 0 && loc.x <= width && loc.y <= height;
}

/*int Board::GetDimension() const
{
	return dimension;
}*/

/*void Board::Check_IsWithinBoard(Location& loc)
{
	if (loc.x >=0 && loc.y >= 0 && loc.x <= width && loc.y <= height)
	{
		isWithinBoard = false;
	}
}

void Board::RefreshIsWithinBoard()
{
	if (isWithinBoard == false)
	{
		isWithinBoard = true;
	}
}

bool Board::IsWithinBoard() const
{
	return isWithinBoard;
}*/

