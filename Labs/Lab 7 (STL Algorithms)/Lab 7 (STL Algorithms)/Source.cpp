
#include "DataTable.h"


using namespace w7;
int main(void) {


	std::ifstream file("Simple.dat");


	DataTable test(file, 12U, 12U);


	std::cout << "Mean: " << test.mean() << std::endl;

}