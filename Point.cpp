#include "Point.h"

template<typename T>
int Point<T>::id = 0;

template<typename T>
int Point<T>::GetId()
{
	return id;
}

template<typename T>
T Point<T>::GetX()
{
	return x;
}

template<typename T>
T Point<T>::GetY()
{
	return y;
}

template<typename T>
void Point<T>::SetX(T x)
{
	this->x = x;
}

template<typename T>
void Point<T>::SetY(T y)
{
	this->y = y;
}


template<typename T>
Point<T>::Point()
{
	id++;
	this->x = 0;
	this->y = 0;
}

//Point::Point(double x, double y)
//{
//	id++;
//	this->x = x;
//	this->y = y;
//}

template<typename T>
Point<T>::~Point()
{

}
