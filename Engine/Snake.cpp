#include "Snake.h"
#include <assert.h>

Snake::Snake(const Location& loc)
{
	segments[0].InitHead(loc);

}

void Snake::MoveBy(const Location& delta_loc)
{
		for (int i = nSegments - 1; i > 0; i--)
		{
			segments[i].Follow(segments[i - 1]);
		}
		segments[0].MoveBy(delta_loc);
}

void Snake::Grow()
{
	if (nSegments < nSegmentsMax)
	{
		nSegments++;
	}
}

void Snake::Draw(Board& brd) const
{
	for (int i = 0; i < nSegments; i++)
	{
		segments[i].Draw(brd);
	}
}

Location Snake::GetLocationOfHead() const
{
	return segments[0].GetLocation();
}

void Snake::ClampToboard(const Board& brd)
{
	segments[0].ClampToBoard(brd);
}

void Snake::Segment::InitHead(const Location& in_loc)
{
	loc = in_loc;
	c = Snake::headColor;
}

void Snake::Segment::InitBody()
{
	c = Snake::bodyColor;
}

void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(const Location& delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1); // x or y is one or negative one.
	loc.Add(delta_loc);
}

void Snake::Segment::Draw(Board& brd) const
{
	
		brd.DrawCell(loc, c);
}

Location Snake::Segment::GetLocation() const
{
	return loc;
}

void Snake::Segment::ClampToBoard(const Board& brd)
{
	if (loc.x >= brd.GetGridWidth())
	{
		loc.x = brd.GetGridWidth();
	}
	if (loc.x < 1)
	{
		loc.x = 0;
	}
	if (loc.y  >= brd.GetGridHeight())
	{
		loc.y = brd.GetGridHeight();
	}
	if (loc.y < 1)
	{
		loc.y = 0;
	}
}



