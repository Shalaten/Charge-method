#pragma once

#include "Edge.h"
#include <vector>

class Graph {
public:
	std::vector<Point>& GetPoints();
	std::vector<std::vector<Edge>>& GetEdges();
	void GenerateRandPoints(int amount);
	void GenerateEdgeMatrix();
	void GenerateCharges();
	void FindMostChargePoints();
	std::vector<int>& GetChargePoints();
	std::vector<std::vector<int>>& GetShortWays();
	void FindWays();
private:
	int pointsAmount = 0;
	std::vector<int> chargePoints;
	std::vector<std::vector<int>> shortWays;
	std::vector<Point> points;
	std::vector<std::vector<Edge>> edges;
};