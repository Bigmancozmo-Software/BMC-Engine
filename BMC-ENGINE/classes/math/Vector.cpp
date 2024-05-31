#include "Vector.h"

// Vector2

Vector2::Vector2(int x, int y)
{
	this->x = x;
	this->y = y;
}

Vector2::Vector2(int xy)
{
	this->x = xy;
	this->y = xy;
}

Vector2::Vector2()
{
	this->x = 0;
	this->y = 0;
}

// Vector3

Vector3::Vector3(int x, int y, int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::Vector3(int xyz)
{
	this->x = xyz;
	this->y = xyz;
	this->z = xyz;
}

Vector3::Vector3()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}