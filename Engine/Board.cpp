#include "Board.h"
#include <assert.h>

Board::Board(Graphics& gfx)
	:
	gfx(gfx)
{
}

void Board::DrawCell( const Location& loc, Color c)
{
	if (IsWithinTheBoard(loc))
	{
		gfx.DrawRectDim(loc.x * dimension, loc.y * dimension, dimension, dimension, c);
	}
}

int Board::GetGridWidth()
{
	return width;
}

int Board::GetGridHeight()
{
	return height;
}

bool Board::IsWithinTheBoard(const Location& loc) const
{
	return loc.x >= 0 && loc.y >= 0 && loc.x < width && loc.y < height;
}
