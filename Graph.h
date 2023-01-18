#pragma once

#include "Edge.h"
#include <vector>

class Graph {
public:
	std::vector<Point>& GetPoints();
	std::vector<std::vector<Edge>>& GetEdges();
	std::vector<std::vector<double>>& GetCharges();
	void GenerateRandPoints(int amount);
	void GenerateEdgeMatrix();
	void GenerateCharges();
	int pointsAmount = 0;

private:
	std::vector<Point> points;
	std::vector<std::vector<Edge>> edges;
	std::vector<std::vector<double>> charges;
};