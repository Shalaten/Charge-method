#include "Graph.h"

std::vector<Point> Graph::GetPoints()
{

	return std::vector<Point>();
}

std::vector<std::vector<Edge>> Graph::GetEdges()
{

	return std::vector<std::vector<Edge>>();
}

void Graph::GeneratePoints(int amount)
{
	if (points.capacity() == 0) {
		points.reserve(amount);
		for (int i = 0; i < amount; ++i) {
			
		}
	}
}
