#include "Graph.h"



std::vector<Point>& Graph::GetPoints()
{

	return points;
}

std::vector<std::vector<Edge>>& Graph::GetEdges()
{

	return edges;
}

std::vector<std::vector<double>>& Graph::GetCharges()
{
	return charges;
}

void Graph::GenerateRandPoints(int amount)
{
	if (points.capacity() == 0) {
		points.resize(amount);
		for (int i = 0; i < amount; ++i) {
			double randX = rand() % 2;
			double randY = rand() % 2;
			points[i].SetX(randX == 1 ? rand() % 1000 : rand() % 1000 * -1);
			points[i].SetY(randY == 1 ? rand() % 800 : rand() % 800 * -1);
		}
		// init pointsAmount
		pointsAmount = points.size();
	}
}

void Graph::GenerateEdgeMatrix()
{
	if (edges.size() == 0) {
		edges.reserve(pointsAmount);
		for (int i = 0; i < pointsAmount; i++) {
			std::vector<Edge> insideArr;
			insideArr.reserve(pointsAmount);
			for (int j = 0; j < pointsAmount; j++) {
				if (i != j) {
					insideArr.push_back(Edge((GetPoints())[i], (GetPoints())[j]));
				}
				else
				{
					insideArr.push_back(Edge());
				}
			}
			edges.push_back(insideArr);
		}
	}
}

void Graph::GenerateCharges()
{
	charges.resize(pointsAmount);
	for (auto& charge : charges) {
		charge.resize(pointsAmount);
	}
	for (int oneP = 0; oneP < pointsAmount; oneP++) {
		for (int twoP = 0; twoP < pointsAmount; twoP++) {
			if (oneP != twoP) {
				for (int threeP = 0; threeP < pointsAmount; threeP++) {
					if (threeP != twoP && threeP != oneP) {
						for (int fourP = 0; fourP < pointsAmount; fourP++) {
							if (fourP != oneP && fourP != twoP && fourP != threeP) {
								double oneSum = edges[oneP][twoP].GetLength() + edges[threeP][fourP].GetLength();
								double twoSum = edges[twoP][threeP].GetLength() + edges[oneP][fourP].GetLength();
								double threeSum = edges[oneP][threeP].GetLength() + edges[twoP][fourP].GetLength();
								//----------------------------|
								if (oneSum > twoSum && twoSum > threeSum){}
								if (oneSum > threeSum && threeSum > twoSum){}
								if (oneSum > twoSum && twoSum == threeSum){}
								if (twoSum == threeSum && twoSum > oneSum){}

								if (twoSum > oneSum && oneSum > threeSum){}
								if (twoSum > threeSum && threeSum > oneSum){}
								if (twoSum > oneSum && oneSum == threeSum){}
								if (oneSum == threeSum && oneSum > twoSum){}

								if (threeSum > oneSum && oneSum > twoSum){}
								if (threeSum > twoSum && twoSum > oneSum){}
								if (threeSum > oneSum && oneSum == twoSum){}
								if (oneSum == twoSum && oneSum > threeSum){}

								if (oneSum == twoSum && twoSum == threeSum){}
							}
						}
					}
				}
			}
		}
	}
}


