#pragma once

struct Location
{
	void Add(const Location& val)
	{
		x += val.x;
		y += val.y;
	}
	Location(int in_x, int in_y)
	{
		x = in_x;
		y = in_y;
	}
	int x;
	int y;
};