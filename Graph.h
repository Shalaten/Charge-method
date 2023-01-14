#pragma once

#include "Edge.h"
#include <vector>

class Graph {
public:
	std::vector<Point> GetPoints();
	std::vector<std::vector<Edge>> GetEdges();
	void GeneratePoints(int amount);

private:
	std::vector<Point> points;
	std::vector<std::vector<Edge>> edges;

	
	
};