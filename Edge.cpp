#include "Edge.h"

Edge::~Edge()
{

}

double Edge::GetLength()
{
	return length;
}

double Edge::GetCharge()
{
	return charge;
}

void Edge::SetCharge(double charge)
{
	this->charge = charge;
}

Edge::Edge()
{
}

Edge::Edge(Point &onePoint, Point &twoPoint)
{
	this->onePoint = onePoint;
	this->twoPoint = twoPoint;
	length = FindLength();
}



double Edge::FindLength()
{
	double onePointX = onePoint.GetX();
	double onePointY = onePoint.GetY();
	double twoPointX = twoPoint.GetX();
	double twoPointY = twoPoint.GetY();
	return sqrt(pow(onePointX - twoPointX, 2) + pow(onePointY - twoPointY, 2));
}
