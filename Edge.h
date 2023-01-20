#pragma once

#include "Point.h"

class Edge {
public:
	Edge();
	Edge(Point &onePoint, Point &twoPoint);
	~Edge();
	double GetLength();
	double GetCharge();
	void SetCharge(double charge);
private:
	Point onePoint, twoPoint;
	double length = 0;
	double charge = 0;
	double FindLength();
};