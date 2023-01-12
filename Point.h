#pragma once

template <typename T>
class Point {
public:
	Point();
	/*Point(double x, double y);*/
	~Point();

	int GetId();
	T GetX();
	T GetY();

	void SetX(T x);
	void SetY(T y);
private:
	int  static id;
	T x, y;
};