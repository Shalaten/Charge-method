#include "Edge.h"

Edge::~Edge()
{

}

Edge::Edge(Point &onePoint, Point &twoPoint)
{
	this->onePoint = onePoint;
	this->twoPoint = twoPoint;
}



double Edge::FindLength()
{
	double onePointX = onePoint.GetX();
	double onePointY = onePoint.GetY();
	double twoPointX = twoPoint.GetX();
	double twoPointY = twoPoint.GetY();
	return sqrt(pow(onePointX - twoPointX, 2) + pow(onePointY - twoPointY, 2));
}
