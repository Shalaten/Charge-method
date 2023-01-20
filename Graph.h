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

private:
	int pointsAmount = 0;
	std::vector<Point> points;
	std::vector<std::vector<Edge>> edges;
	std::vector<std::vector<double>> charges;
};