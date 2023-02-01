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
	void SumChargeGenerate(int oneS, int twoS, int threeS, int fourS, double chargeS);
	void EdgeCompare(Edge& minEdgeOne, Edge& minEdgeTwo, Edge& middleEdgeOne, Edge& middleEdgeTwo, Edge& maxEdgeOne, Edge& maxEdgeTwo);
	void SumTestPlus(int oneS, int twoS, int threeS, int fourS, double chargeS);
	void SumTestMinus(int oneS, int twoS, int threeS, int fourS, double chargeS);

	void FindMostChargePoints();
	std::vector<int>& GetChargePoints();
	std::vector<std::vector<int>>& GetShortWays();
	void FindWays();
	void FindWaysRecursion(int lastPoint, std::vector<int>& way, std::vector<bool>& usedPoints);
	void BroodForce(std::vector<int> wayM, int counterM, double sumWeightM, int lastPoint, std::vector<bool> checkedPointsM);
	void ShortWayUseBroodForce();
	double minWeight = 10000000;
	std::vector<int> minWay;

	void PrintShortWays();
private:
	int pointsAmount = 0;
	std::vector<int> chargePoints;
	std::vector<std::vector<int>> shortWays;
	std::vector<Point> points;
	std::vector<std::vector<Edge>> edges;
};