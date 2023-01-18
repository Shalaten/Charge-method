#include "Graph.h"
#include <array>


int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	Graph graph;

	int amount = 10;
	std::cout << "Amount of Vertices:    ";
	//std::cin >> amount;
	std::cout << std::endl;


	graph.GenerateRandPoints(amount);
	graph.GenerateEdgeMatrix();
	graph.GenerateCharges();
	// Печать
	for (int i = 0; i < amount; ++i) {
		for (int j = 0; j < amount; ++j) {
			std::cout << graph.GetEdges()[i][j].GetLength() << "\t";
		}
		std::cout << std::endl;
	}

	


	/*for (auto& point : graph.GetPoints()) {

		std::cout << "X-   "<< point.GetX()<<"    Y-   "<< point.GetY() << std::endl;
	}*/
	system("pause");
	return 0;
}






