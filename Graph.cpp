#include "Graph.h"



std::vector<Point>& Graph::GetPoints()
{

	return points;
}

std::vector<std::vector<Edge>>& Graph::GetEdges()
{

	return edges;
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
		// init chargePoints
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
								// ONE ONE ONE ONE ONE
								if (oneSum > twoSum && twoSum > threeSum) {
									edges[oneP][twoP].SetCharge(edges[oneP][twoP].GetCharge() - 3);
									edges[threeP][fourP].SetCharge(edges[threeP][fourP].GetCharge() - 3);

									edges[oneP][threeP].SetCharge(edges[oneP][threeP].GetCharge() + 2);
									edges[twoP][fourP].SetCharge(edges[twoP][fourP].GetCharge() + 2);

									edges[twoP][threeP].SetCharge(edges[twoP][threeP].GetCharge() + 1);
									edges[oneP][fourP].SetCharge(edges[oneP][fourP].GetCharge() + 1);
								}
								if (oneSum > threeSum && threeSum > twoSum) {
									edges[oneP][twoP].SetCharge(edges[oneP][twoP].GetCharge() - 3);
									edges[threeP][fourP].SetCharge(edges[threeP][fourP].GetCharge() - 3);

									edges[twoP][threeP].SetCharge(edges[twoP][threeP].GetCharge() + 2);
									edges[oneP][fourP].SetCharge(edges[oneP][fourP].GetCharge() + 2);

									edges[oneP][threeP].SetCharge(edges[oneP][threeP].GetCharge() + 1);
									edges[twoP][fourP].SetCharge(edges[twoP][fourP].GetCharge() + 1);
								}
								if (oneSum > twoSum && twoSum == threeSum) { 
									edges[oneP][twoP].SetCharge(edges[oneP][twoP].GetCharge() - 3);
									edges[threeP][fourP].SetCharge(edges[threeP][fourP].GetCharge() - 3);

									edges[twoP][threeP].SetCharge(edges[twoP][threeP].GetCharge() + 1.5);
									edges[oneP][fourP].SetCharge(edges[oneP][fourP].GetCharge() + 1.5);

									edges[oneP][threeP].SetCharge(edges[oneP][threeP].GetCharge() + 1.5);
									edges[twoP][fourP].SetCharge(edges[twoP][fourP].GetCharge() + 1.5);
								}
								if (twoSum == threeSum && twoSum > oneSum) {
									edges[oneP][threeP].SetCharge(edges[oneP][threeP].GetCharge() - 1.5);
									edges[twoP][fourP].SetCharge(edges[twoP][fourP].GetCharge() - 1.5);

									edges[twoP][threeP].SetCharge(edges[twoP][threeP].GetCharge() - 1.5);
									edges[oneP][fourP].SetCharge(edges[oneP][fourP].GetCharge() - 1.5);

									edges[oneP][twoP].SetCharge(edges[oneP][twoP].GetCharge() + 3);
									edges[threeP][fourP].SetCharge(edges[threeP][fourP].GetCharge() + 3);
								}
								// TWO TWO TWO TWO TWO
								if (twoSum > oneSum && oneSum > threeSum) {
									edges[twoP][threeP].SetCharge(edges[twoP][threeP].GetCharge() - 3);
									edges[oneP][fourP].SetCharge(edges[oneP][fourP].GetCharge() - 3);

									edges[oneP][twoP].SetCharge(edges[oneP][twoP].GetCharge() + 1);
									edges[threeP][fourP].SetCharge(edges[threeP][fourP].GetCharge() + 1);

									edges[oneP][threeP].SetCharge(edges[oneP][threeP].GetCharge() + 2);
									edges[twoP][fourP].SetCharge(edges[twoP][fourP].GetCharge() + 2);
								}
								if (twoSum > threeSum && threeSum > oneSum) {
									edges[twoP][threeP].SetCharge(edges[twoP][threeP].GetCharge() - 3);
									edges[oneP][fourP].SetCharge(edges[oneP][fourP].GetCharge() - 3);

									edges[oneP][threeP].SetCharge(edges[oneP][threeP].GetCharge() + 1);
									edges[twoP][fourP].SetCharge(edges[twoP][fourP].GetCharge() + 1);

									edges[oneP][twoP].SetCharge(edges[oneP][twoP].GetCharge() + 2);
									edges[threeP][fourP].SetCharge(edges[threeP][fourP].GetCharge() + 2);
								}
								if (twoSum > oneSum && oneSum == threeSum) {
									edges[twoP][threeP].SetCharge(edges[twoP][threeP].GetCharge() - 3);
									edges[oneP][fourP].SetCharge(edges[oneP][fourP].GetCharge() - 3);

									edges[oneP][threeP].SetCharge(edges[oneP][threeP].GetCharge() + 1.5);
									edges[twoP][fourP].SetCharge(edges[twoP][fourP].GetCharge() + 1.5);

									edges[oneP][twoP].SetCharge(edges[oneP][twoP].GetCharge() + 1.5);
									edges[threeP][fourP].SetCharge(edges[threeP][fourP].GetCharge() + 1.5);
								}
								if (oneSum == threeSum && oneSum > twoSum) {
									edges[oneP][twoP].SetCharge(edges[oneP][twoP].GetCharge() - 1.5);
									edges[threeP][fourP].SetCharge(edges[threeP][fourP].GetCharge() - 1.5);

									edges[oneP][threeP].SetCharge(edges[oneP][threeP].GetCharge() - 1.5);
									edges[twoP][fourP].SetCharge(edges[twoP][fourP].GetCharge() - 1.5);

									edges[twoP][threeP].SetCharge(edges[twoP][threeP].GetCharge() + 3);
									edges[oneP][fourP].SetCharge(edges[oneP][fourP].GetCharge() + 3);
								}
								// THREE THREE THREE THREE THREE
								if (threeSum > oneSum && oneSum > twoSum) {
									edges[oneP][threeP].SetCharge(edges[oneP][threeP].GetCharge() - 3);
									edges[twoP][fourP].SetCharge(edges[twoP][fourP].GetCharge() - 3);

									edges[oneP][twoP].SetCharge(edges[oneP][twoP].GetCharge() + 1);
									edges[threeP][fourP].SetCharge(edges[threeP][fourP].GetCharge() + 1);

									edges[twoP][threeP].SetCharge(edges[twoP][threeP].GetCharge() + 3);
									edges[oneP][fourP].SetCharge(edges[oneP][fourP].GetCharge() + 2);
								}
								if (threeSum > twoSum && twoSum > oneSum) {
									edges[oneP][threeP].SetCharge(edges[oneP][threeP].GetCharge() - 3);
									edges[twoP][fourP].SetCharge(edges[twoP][fourP].GetCharge() - 3);

									edges[oneP][twoP].SetCharge(edges[oneP][twoP].GetCharge() + 1);
									edges[threeP][fourP].SetCharge(edges[threeP][fourP].GetCharge() + 1);

									edges[twoP][threeP].SetCharge(edges[twoP][threeP].GetCharge() + 2);
									edges[oneP][fourP].SetCharge(edges[oneP][fourP].GetCharge() + 2);
								}
								if (threeSum > oneSum && oneSum == twoSum) {
									edges[oneP][threeP].SetCharge(edges[oneP][threeP].GetCharge() - 3);
									edges[twoP][fourP].SetCharge(edges[twoP][fourP].GetCharge() - 3);

									edges[oneP][twoP].SetCharge(edges[oneP][twoP].GetCharge() + 1.5);
									edges[threeP][fourP].SetCharge(edges[threeP][fourP].GetCharge() + 1.5);

									edges[twoP][threeP].SetCharge(edges[twoP][threeP].GetCharge() + 1.5);
									edges[oneP][fourP].SetCharge(edges[oneP][fourP].GetCharge() + 1.5);
								}
								if (oneSum == twoSum && oneSum > threeSum) {
									edges[oneP][twoP].SetCharge(edges[oneP][twoP].GetCharge() - 1.5);
									edges[threeP][fourP].SetCharge(edges[threeP][fourP].GetCharge() - 1.5);

									edges[twoP][threeP].SetCharge(edges[twoP][threeP].GetCharge() - 1.5);
									edges[oneP][fourP].SetCharge(edges[oneP][fourP].GetCharge() - 1.5);

									edges[oneP][threeP].SetCharge(edges[oneP][threeP].GetCharge() + 3);
									edges[twoP][fourP].SetCharge(edges[twoP][fourP].GetCharge() + 3);
								}

								if (oneSum == twoSum && twoSum == threeSum){}
							}
						}
					}
				}
			}
		}
	}
}

void Graph::FindMostChargePoints()
{
	std::vector<bool> testChargePoints;
	testChargePoints.resize(pointsAmount);
	double maxCharge = 0;
	for (int i = 0; i < pointsAmount; ++i) {
		for (int j = i + 1; j < pointsAmount; ++j) {
			if (edges[i][j].GetCharge() > maxCharge)
				maxCharge = edges[i][j].GetCharge();
		}
	}
	for (int i = 0; i < pointsAmount; ++i) {
		for (int j = i + 1; j < pointsAmount; ++j) {
			if (edges[i][j].GetCharge() == maxCharge) {
				testChargePoints[i] = true;
				testChargePoints[j] = true;
			}
		}
	}
	for (int i = 0; i < pointsAmount; ++i) {
		if (testChargePoints[i])
			chargePoints.push_back(i);
	}
}

std::vector<int>& Graph::GetChargePoints()
{
	return chargePoints;
}

std::vector<std::vector<int>>& Graph::GetShortWays()
{
	return shortWays;
}

void Graph::FindWays()
{
	for (const auto& point : chargePoints) {
		std::vector<int> way;
		way.reserve(pointsAmount + 1);
		way.push_back(point);
		std::vector<bool> usedPoints;
		usedPoints.resize(pointsAmount);
		usedPoints[point] = true;
		FindWaysRecursion(point, way, usedPoints);
	}
}

void Graph::FindWaysRecursion(int lastPoint, std::vector<int> &way, std::vector<bool>& usedPoints)
{
	double maxCharge = -1000000;
	double maxPoint = NULL;
	for (int i = 0; i < pointsAmount; ++i) {
		if (edges[lastPoint][i].GetCharge() > maxCharge && !usedPoints[i] && lastPoint != i) {
			maxCharge = edges[lastPoint][i].GetCharge();
			maxPoint = i;
		}
	}
	way.push_back(maxPoint);
	lastPoint = maxPoint;
	usedPoints[maxPoint] = true;
	if (way.size() != pointsAmount) 
		FindWaysRecursion(lastPoint, way, usedPoints);
	else {
		way.push_back(way[0]);
		shortWays.push_back(way);
	}
}

void Graph::BroodForce(std::vector<int> wayM, int counterM, double sumWeightM, int lastPoint, std::vector<bool> checkedPointsM)
{
	for (int i = 0; i < pointsAmount; i++) {
		int counter = counterM + 1;
		double sumWeight = sumWeightM;
		std::vector<int> way = wayM;
		std::vector<bool> checkedPoints = checkedPointsM;
		if (edges[lastPoint][i].GetLength() != 0) {
			if (counter < pointsAmount - 1 && !checkedPoints[i]) {
				sumWeight += edges[lastPoint][i].GetLength();
				way.push_back(i);
				checkedPoints[i] = true;
				BroodForce(way, counter, sumWeight, i, checkedPoints);
			}
			else if (counter == pointsAmount - 1 && !checkedPoints[i]) {
				sumWeight += edges[i][lastPoint].GetLength();
				sumWeight += edges[way[0]][i].GetLength();
				way.push_back(i);
				if (sumWeight < minWeight) {
					minWay = way;
					minWeight = sumWeight;
				}
			}
		}
	}
}

void Graph::ShortWayUseBroodForce()
{
	for (int i = 0; i < pointsAmount; ++i) {
		int counter = 0;
		double sumWeight = 0;
		std::vector<int> way;
		way.push_back(i);
		std::vector<bool> checkedPoints;
		checkedPoints.resize(pointsAmount);
		checkedPoints[i] = true;
		BroodForce(way, counter, sumWeight, i, checkedPoints);
	}
}

void Graph::PrintShortWays()
{
	for (const auto& shortWay : shortWays) {
		double commonWeight = 0;
		for (int j = 0; j < pointsAmount; ++j) {
			commonWeight += edges[shortWay[j]][shortWay[j + 1]].GetLength();
			std::cout << shortWay[j]<< " - " << shortWay[j + 1] << "\t" << edges[shortWay[j]][shortWay[j + 1]].GetLength() << "\t | \t";
		}
		std::cout << "Weight -   " << commonWeight << std::endl;
	}
}

