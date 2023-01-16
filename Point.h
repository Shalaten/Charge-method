#pragma once

#include "main.h"

class Point {
public:
	Point();
	Point(double x, double y);

	int GetId();

	double GetX();
	double GetY();

	void SetX(double x);
	void SetY(double y);
	~Point();
private:
	int  static id;
	double x, y;
};