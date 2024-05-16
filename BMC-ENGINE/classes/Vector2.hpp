#pragma once

class Vector2 {
public:
	int x, y;
	
	Vector2(int x, int y);

	Vector2 zero = new Vector2(0, 0);
};

Vector2::Vector2(int x, int y)
{
	this->x = x;
	this->y = y;
}