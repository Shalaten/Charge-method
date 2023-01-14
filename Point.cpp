#include "Point.h"

int Point::id = 0;

int Point::GetId()
{
	return id;
}

double Point::GetX()
{
	return x;
}

double Point::GetY()
{
	return y;
}

void Point::SetX(double x)
{
	this->x = x;
}

void Point::SetY(double y)
{
	this->y = y;
}

Point::Point()
{
	id++;
	this->x = 0;
	this->y = 0;
}

Point::Point(double x, double y)
{
	id++;
	this->x = x;
	this->y = y;
}

Point::~Point()
{

}
