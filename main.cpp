#include "Graph.h"


int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	Graph graph;
	
	std::cout << "Size-   " << graph.GetPoints().size() << std::endl;
	for (auto& point : graph.GetPoints()) {

		std::cout << "X-   "<< point.GetX()<<"    Y-   "<< point.GetY() << std::endl;
	}
	system("pause");
	return 0;
}






