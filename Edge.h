#pragma once

#include "Point.h"

class Edge {
public:
	Edge(Point &onePoint, Point &twoPoint);
	~Edge();
	double GetLength();
private:
	Point onePoint, twoPoint;
	double length = 0;
	double FindLength();
};