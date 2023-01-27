#include "Graph.h"
#include <array>


int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "ru");
	//srand(time(NULL));

	Graph graph;

	int amount = 6;
	std::cout << "Amount of Vertices:    ";
	//std::cin >> amount;
	std::cout << std::endl;


	graph.GenerateRandPoints(amount);
	graph.GenerateEdgeMatrix();
	graph.GenerateCharges();
	graph.FindMostChargePoints();

	for (int i = 0; i < amount; ++i) {
		for (int j = 0; j < amount; ++j) {
			std::cout << graph.GetEdges()[i][j].GetLength() << "\t";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	for (int i = 0; i < amount; ++i) {
		for (int j = 0; j < amount; ++j) {
			std::cout << graph.GetEdges()[i][j].GetCharge() << "\t";
		}
		std::cout << std::endl;
	}


	graph.FindWays();
	std::cout << std::endl;
	for (int i = 0; i < graph.GetChargePoints().size(); ++i)
		std::cout << graph.GetChargePoints()[i] << "\t";

	std::cout << std::endl;
	std::cout << std::endl;
	graph.PrintShortWays();

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "BROOD FORCE" << std::endl;
	graph.ShortWayUseBroodForce();
	for (auto point : graph.minWay) {
		std::cout << point << "\t";
	}
	std::cout << "Weight - "<< graph.minWeight << std::endl;
	
	
	

	system("pause");
	return 0;
}






