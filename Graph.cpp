#include "Graph.h"

Graph::Graph()
{
	GenerateRandPoints(3);
}

std::vector<Point>& Graph::GetPoints()
{

	return points;
}

std::vector<std::vector<Edge>> Graph::GetEdges()
{

	return std::vector<std::vector<Edge>>();
}

void Graph::GenerateRandPoints(int amount)
{
	if (points.capacity() == 0) {
		points.resize(amount);
		for (int i = 0; i < amount; ++i) {
			points[i].SetX(rand() % 1000));
			points[i].SetY(rand() % 800);
		}
	}
}
