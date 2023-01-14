#include "Graph.h"
#include <ctime>

struct A
{
	int a;
	A(int a) {
		this->a = a;
	}
};

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	std::vector<A> arr;

	A r(3);
	arr.push_back(r);
	

	std::cout << "Size   " << arr.size(); 
	std::cout <<"   " <<  arr[0].a << std::endl;
	system("pause");
	return 0;
}






