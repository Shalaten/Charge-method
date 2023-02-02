#include "Graph.h"
#define CHARGE


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
									EdgeCompare(edges[oneP][threeP], edges[twoP][fourP], edges[twoP][threeP], edges[oneP][fourP], edges[oneP][twoP], edges[threeP][fourP]);
								}
								else if (oneSum > threeSum && threeSum > twoSum) {
									EdgeCompare(edges[twoP][threeP], edges[oneP][fourP], edges[oneP][threeP], edges[twoP][fourP], edges[oneP][twoP], edges[threeP][fourP]);
								}
								else if (oneSum > twoSum && twoSum == threeSum) { 
									std::cout << "FAIL" << std::endl;
									SumChargeGenerate(oneP, twoP, threeP, fourP, -3);

									SumChargeGenerate(twoP, threeP, oneP, fourP, 1.5);

									SumChargeGenerate(oneP, threeP, twoP, fourP, 1.5);
								}
								else if (twoSum == threeSum && twoSum > oneSum) {
									std::cout << "FAIL" << std::endl;
									SumChargeGenerate(oneP, threeP, twoP, fourP, -1.5);

									SumChargeGenerate(twoP, threeP, oneP, fourP, -1.5);

									SumChargeGenerate(oneP, twoP, threeP, fourP, 3);
								} 
								// TWO TWO TWO TWO TWO
								else if (twoSum > oneSum && oneSum > threeSum) {
									EdgeCompare(edges[oneP][threeP], edges[twoP][fourP], edges[oneP][twoP], edges[threeP][fourP], edges[twoP][threeP], edges[oneP][fourP]);
								}
								else if (twoSum > threeSum && threeSum > oneSum) {
									EdgeCompare(edges[oneP][twoP], edges[threeP][fourP], edges[oneP][threeP], edges[twoP][fourP], edges[twoP][threeP], edges[oneP][fourP]);
								}
								else if (twoSum > oneSum && oneSum == threeSum) {
									SumChargeGenerate(twoP, threeP, oneP, fourP, -3);

									SumChargeGenerate(oneP, threeP, twoP, fourP, 1.5);

									SumChargeGenerate(oneP, twoP, threeP, fourP, 1.5);
								}
								else if (oneSum == threeSum && oneSum > twoSum) {
									SumChargeGenerate(oneP, threeP, twoP, fourP, -1.5);

									SumChargeGenerate(oneP, twoP, threeP, fourP, -1.5);

									SumChargeGenerate(twoP, threeP, oneP, fourP, 3);
								}
								// THREE THREE THREE THREE THREE
								else if (threeSum > oneSum && oneSum > twoSum) {
									EdgeCompare(edges[twoP][threeP], edges[oneP][fourP], edges[oneP][twoP], edges[threeP][fourP], edges[oneP][threeP], edges[twoP][fourP]);
								}
								else if (threeSum > twoSum && twoSum > oneSum) {
									EdgeCompare(edges[oneP][twoP], edges[threeP][fourP], edges[twoP][threeP], edges[oneP][fourP], edges[oneP][threeP], edges[twoP][fourP]);
								}
								else if (threeSum > oneSum && oneSum == twoSum) {
									SumChargeGenerate(oneP, threeP, twoP, fourP, -3);

									SumChargeGenerate(oneP, twoP, threeP, fourP, 1.5);

									SumChargeGenerate(twoP, threeP, oneP, fourP, 1.5);
								}
								else if (oneSum == twoSum && oneSum > threeSum) {
									SumChargeGenerate(oneP, twoP, threeP, fourP, -1.5);

									SumChargeGenerate(twoP, threeP, oneP, fourP, -1.5);

									SumChargeGenerate(oneP, threeP, twoP, fourP, 3);
								}

								else if (oneSum == twoSum && twoSum == threeSum) {
									std::cout << "FAIL" << std::endl;
								}
							}
						}
					}
				}
			}
		}
	}
}

void Graph::SumChargeGenerate(int oneS, int twoS, int threeS, int fourS, double chargeS)
{
	edges[oneS][twoS].SetCharge(edges[oneS][twoS].GetCharge() + chargeS);
	edges[threeS][fourS].SetCharge(edges[threeS][fourS].GetCharge() + chargeS);
}



void Graph::SumTestPlus(int oneS, int twoS, int threeS, int fourS, double chargeS) {
	if (edges[oneS][twoS].GetLength() > edges[threeS][fourS].GetLength()) {
		edges[oneS][twoS].SetCharge(edges[oneS][twoS].GetCharge() + chargeS / 2);
		edges[threeS][fourS].SetCharge(edges[threeS][fourS].GetCharge() + chargeS);
	}
	else if (edges[oneS][twoS].GetLength() < edges[threeS][fourS].GetLength()) {
		edges[oneS][twoS].SetCharge(edges[oneS][twoS].GetCharge() + chargeS);
		edges[threeS][fourS].SetCharge(edges[threeS][fourS].GetCharge() + chargeS / 2);
	}
	else if (edges[oneS][twoS].GetLength() == edges[threeS][fourS].GetLength()) {
		edges[oneS][twoS].SetCharge(edges[oneS][twoS].GetCharge() + 1.5 * chargeS / 2);
		edges[threeS][fourS].SetCharge(edges[threeS][fourS].GetCharge() + 1.5 * chargeS / 2);
	}
}

void Graph::EdgeCompare(Edge& minEdgeOne, Edge& minEdgeTwo, Edge& middleEdgeOne, Edge& middleEdgeTwo, Edge& maxEdgeOne, Edge& maxEdgeTwo)
{
	
#ifdef CHARGE
	bool plusStateCharge = false;
	bool minusStateCharge = false;
	double stateCharge = 0;
	if ((middleEdgeOne.GetLength() < minEdgeOne.GetLength() && middleEdgeOne.GetLength() < minEdgeTwo.GetLength())
		|| (middleEdgeTwo.GetLength() < minEdgeOne.GetLength() && middleEdgeTwo.GetLength() < minEdgeTwo.GetLength())
		|| (minEdgeOne.GetLength() > middleEdgeOne.GetLength() && minEdgeOne.GetLength() > middleEdgeTwo.GetLength())
			|| (minEdgeTwo.GetLength() > middleEdgeOne.GetLength() && minEdgeTwo.GetLength() > middleEdgeTwo.GetLength())) {
		stateCharge++;
		plusStateCharge = true;
	}
	if ((middleEdgeOne.GetLength() > maxEdgeOne.GetLength() && middleEdgeOne.GetLength() > maxEdgeTwo.GetLength())
		|| (middleEdgeTwo.GetLength() > maxEdgeOne.GetLength() && middleEdgeTwo.GetLength() > maxEdgeTwo.GetLength())
		|| (maxEdgeOne.GetLength() < middleEdgeOne.GetLength() && maxEdgeOne.GetLength() < middleEdgeTwo.GetLength())
			|| (maxEdgeTwo.GetLength() < middleEdgeOne.GetLength() && maxEdgeTwo.GetLength() < middleEdgeTwo.GetLength())) {
		stateCharge--;
		minusStateCharge = true;
	}
	if (middleEdgeOne.GetLength() < minEdgeOne.GetLength() || middleEdgeOne.GetLength() < minEdgeTwo.GetLength()
		|| middleEdgeTwo.GetLength() < minEdgeOne.GetLength() || middleEdgeTwo.GetLength() < minEdgeTwo.GetLength()) {
		if (stateCharge != 1 && !plusStateCharge) {
			stateCharge += 0.5;
		}
	}
	if (middleEdgeOne.GetLength() > maxEdgeOne.GetLength() || middleEdgeOne.GetLength() > maxEdgeTwo.GetLength()
		|| middleEdgeTwo.GetLength() > maxEdgeOne.GetLength() || middleEdgeTwo.GetLength() > maxEdgeTwo.GetLength()) {
		if (stateCharge != -1 && !minusStateCharge) {
			stateCharge -= 0.5;
		}
	}
	///////////////////////////////////////////////////
	if (stateCharge == 0) {
		// min Edges
		minEdgeOne.SetCharge(minEdgeOne.GetCharge() + 3);
		minEdgeTwo.SetCharge(minEdgeTwo.GetCharge() + 3);
		// middle Edges
			   // (0; 0)
		// max Edges
		maxEdgeOne.SetCharge(maxEdgeOne.GetCharge() - 3);
		maxEdgeTwo.SetCharge(maxEdgeTwo.GetCharge() - 3);
		return;
	}
	else if (stateCharge == 1) {
		// min Edges
		minEdgeOne.SetCharge(minEdgeOne.GetCharge() + 2);
		minEdgeTwo.SetCharge(minEdgeTwo.GetCharge() + 2);
		// middle Edges
		middleEdgeOne.SetCharge(middleEdgeOne.GetCharge() + 1);
		middleEdgeTwo.SetCharge(middleEdgeTwo.GetCharge() + 1);
		// max Edges
		maxEdgeOne.SetCharge(maxEdgeOne.GetCharge() - 3);
		maxEdgeTwo.SetCharge(maxEdgeTwo.GetCharge() - 3);
		return;
	}
	else if (stateCharge == 0.5) {
		// min Edges
		minEdgeOne.SetCharge(minEdgeOne.GetCharge() + 2.5);
		minEdgeTwo.SetCharge(minEdgeTwo.GetCharge() + 2.5);
		// middle Edges
		middleEdgeOne.SetCharge(middleEdgeOne.GetCharge() + 0.5);
		middleEdgeTwo.SetCharge(middleEdgeTwo.GetCharge() + 0.5);
		// max Edges
		maxEdgeOne.SetCharge(maxEdgeOne.GetCharge() - 3);
		maxEdgeTwo.SetCharge(maxEdgeTwo.GetCharge() - 3);
		return;
	}
	else if (stateCharge == -1) {
		// min Edges
		minEdgeOne.SetCharge(minEdgeOne.GetCharge() + 3);
		minEdgeTwo.SetCharge(minEdgeTwo.GetCharge() + 3);
		// middle Edges
		middleEdgeOne.SetCharge(middleEdgeOne.GetCharge() - 1);
		middleEdgeTwo.SetCharge(middleEdgeTwo.GetCharge() - 1);
		// max Edges
		maxEdgeOne.SetCharge(maxEdgeOne.GetCharge() - 2);
		maxEdgeTwo.SetCharge(maxEdgeTwo.GetCharge() - 2);
		return;
	}
	else if (stateCharge == -0.5) {
		// min Edges
		minEdgeOne.SetCharge(minEdgeOne.GetCharge() + 3);
		minEdgeTwo.SetCharge(minEdgeTwo.GetCharge() + 3);
		// middle Edges
		middleEdgeOne.SetCharge(middleEdgeOne.GetCharge() - 0.5);
		middleEdgeTwo.SetCharge(middleEdgeTwo.GetCharge() - 0.5);
		// max Edges
		maxEdgeOne.SetCharge(maxEdgeOne.GetCharge() - 2.5);
		maxEdgeTwo.SetCharge(maxEdgeTwo.GetCharge() - 2.5);
		return;
	}
	///////////////////////////////////////////////////
#else
	bool plusStateCharge = false;
	bool minusStateCharge = false;
	if (((middleEdgeOne.GetLength() < minEdgeOne.GetLength() && middleEdgeOne.GetLength() < minEdgeTwo.GetLength())
		|| (middleEdgeTwo.GetLength() < minEdgeOne.GetLength() && middleEdgeTwo.GetLength() < minEdgeTwo.GetLength()))
		|| ((minEdgeOne.GetLength() > middleEdgeOne.GetLength() && minEdgeOne.GetLength() > middleEdgeTwo.GetLength())
			|| (minEdgeTwo.GetLength() > middleEdgeOne.GetLength() && minEdgeTwo.GetLength() > middleEdgeTwo.GetLength()))) {
		plusStateCharge = true;
	}
	if (((middleEdgeOne.GetLength() > maxEdgeOne.GetLength() && middleEdgeOne.GetLength() > maxEdgeTwo.GetLength())
		|| (middleEdgeTwo.GetLength() > maxEdgeOne.GetLength() && middleEdgeTwo.GetLength() > maxEdgeTwo.GetLength()))
		|| ((maxEdgeOne.GetLength() < middleEdgeOne.GetLength() && maxEdgeOne.GetLength() < middleEdgeTwo.GetLength())
			|| (maxEdgeTwo.GetLength() < middleEdgeOne.GetLength() && maxEdgeTwo.GetLength() < middleEdgeTwo.GetLength()))) {
		minusStateCharge = true;
	}
	if (plusStateCharge && minusStateCharge) {
		// min Edges
		minEdgeOne.SetCharge(minEdgeOne.GetCharge() + 3);
		minEdgeTwo.SetCharge(minEdgeTwo.GetCharge() + 3);
		// middle Edges
			   // (0; 0)
		// max Edges
		maxEdgeOne.SetCharge(maxEdgeOne.GetCharge() - 3);
		maxEdgeTwo.SetCharge(maxEdgeTwo.GetCharge() - 3);
		return;
	}
	else if (plusStateCharge && !minusStateCharge) {
		// min Edges
		minEdgeOne.SetCharge(minEdgeOne.GetCharge() + 2);
		minEdgeTwo.SetCharge(minEdgeTwo.GetCharge() + 2);
		// middle Edges
		middleEdgeOne.SetCharge(middleEdgeOne.GetCharge() + 1);
		middleEdgeTwo.SetCharge(middleEdgeTwo.GetCharge() + 1);
		// max Edges
		maxEdgeOne.SetCharge(maxEdgeOne.GetCharge() - 3);
		maxEdgeTwo.SetCharge(maxEdgeTwo.GetCharge() - 3);
		return;
	}
	else if (minusStateCharge && !plusStateCharge) {
		// min Edges
		minEdgeOne.SetCharge(minEdgeOne.GetCharge() + 3);
		minEdgeTwo.SetCharge(minEdgeTwo.GetCharge() + 3);
		// middle Edges
		middleEdgeOne.SetCharge(middleEdgeOne.GetCharge() - 1);
		middleEdgeTwo.SetCharge(middleEdgeTwo.GetCharge() - 1);
		// max Edges
		maxEdgeOne.SetCharge(maxEdgeOne.GetCharge() - 2);
		maxEdgeTwo.SetCharge(maxEdgeTwo.GetCharge() - 2);
		return;
	}

	if (middleEdgeOne.GetLength() <= minEdgeOne.GetLength() || middleEdgeOne.GetLength() <= minEdgeTwo.GetLength()
		|| middleEdgeTwo.GetLength() <= minEdgeOne.GetLength() || middleEdgeTwo.GetLength() <= minEdgeTwo.GetLength()) {
		plusStateCharge = true;
	}
	if (middleEdgeOne.GetLength() >= maxEdgeOne.GetLength() || middleEdgeOne.GetLength() >= maxEdgeTwo.GetLength()
		|| middleEdgeTwo.GetLength() >= maxEdgeOne.GetLength() || middleEdgeTwo.GetLength() >= maxEdgeTwo.GetLength()) {
		minusStateCharge = true;
	}
	if (plusStateCharge && minusStateCharge) {
		// min Edges
		minEdgeOne.SetCharge(minEdgeOne.GetCharge() + 3);
		minEdgeTwo.SetCharge(minEdgeTwo.GetCharge() + 3);
		// middle Edges
			   // (0; 0)
		// max Edges
		maxEdgeOne.SetCharge(maxEdgeOne.GetCharge() - 3);
		maxEdgeTwo.SetCharge(maxEdgeTwo.GetCharge() - 3);
		return;
	}
	else if (plusStateCharge && !minusStateCharge) {
		// min Edges
		minEdgeOne.SetCharge(minEdgeOne.GetCharge() + 2.5);
		minEdgeTwo.SetCharge(minEdgeTwo.GetCharge() + 2.5);
		// middle Edges
		middleEdgeOne.SetCharge(middleEdgeOne.GetCharge() + 0.5);
		middleEdgeTwo.SetCharge(middleEdgeTwo.GetCharge() + 0.5);
		// max Edges
		maxEdgeOne.SetCharge(maxEdgeOne.GetCharge() - 3);
		maxEdgeTwo.SetCharge(maxEdgeTwo.GetCharge() - 3);
		return;
	}
	else if (minusStateCharge && !plusStateCharge) {
		// min Edges
		minEdgeOne.SetCharge(minEdgeOne.GetCharge() + 3);
		minEdgeTwo.SetCharge(minEdgeTwo.GetCharge() + 3);
		// middle Edges
		middleEdgeOne.SetCharge(middleEdgeOne.GetCharge() - 0.5);
		middleEdgeTwo.SetCharge(middleEdgeTwo.GetCharge() - 0.5);
		// max Edges
		maxEdgeOne.SetCharge(maxEdgeOne.GetCharge() - 2.5);
		maxEdgeTwo.SetCharge(maxEdgeTwo.GetCharge() - 2.5);
		return;
	}
	// Если не было выполнено ни одно условие, то используется стандартное распределение заряда 
	// min Edges
	minEdgeOne.SetCharge(minEdgeOne.GetCharge() + 3);
	minEdgeTwo.SetCharge(minEdgeTwo.GetCharge() + 3);
	// middle Edges
		   // (0; 0)
	// max Edges
	maxEdgeOne.SetCharge(maxEdgeOne.GetCharge() - 3);
	maxEdgeTwo.SetCharge(maxEdgeTwo.GetCharge() - 3);
#endif // CHARGE

}



void Graph::SumTestMinus(int oneS, int twoS, int threeS, int fourS, double chargeS) {
	if (edges[oneS][twoS].GetLength() > edges[threeS][fourS].GetLength()) {
		edges[oneS][twoS].SetCharge(edges[oneS][twoS].GetCharge() + chargeS);
		edges[threeS][fourS].SetCharge(edges[threeS][fourS].GetCharge() + chargeS / 2);
	}
	else if (edges[oneS][twoS].GetLength() < edges[threeS][fourS].GetLength()) {
		edges[oneS][twoS].SetCharge(edges[oneS][twoS].GetCharge() + chargeS / 2);
		edges[threeS][fourS].SetCharge(edges[threeS][fourS].GetCharge() + chargeS);
	}
	else if (edges[oneS][twoS].GetLength() == edges[threeS][fourS].GetLength()) {
		edges[oneS][twoS].SetCharge(edges[oneS][twoS].GetCharge() + 1.5 * chargeS / 2);
		edges[threeS][fourS].SetCharge(edges[threeS][fourS].GetCharge() + 1.5 * chargeS / 2);
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

