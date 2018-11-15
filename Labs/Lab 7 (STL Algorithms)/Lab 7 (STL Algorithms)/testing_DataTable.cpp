
#include "DataTable.h"


using namespace w7;

const int FW = 8; // field width
const int ND = 4; // precision for numbers


int main(void) {


	std::ifstream file("Simple.dat");


	DataTable<float> test(file, FW, ND);
	float slope, y_inter;

	test.regression(slope, y_inter);



	std::cout << "Mean: " << test.mean() << std::endl;
	std::cout << "Sigma: " << test.sigma() << std::endl;
	std::cout << "Median: " << test.median() << std::endl;
	std::cout << "Slope: " << slope << std::endl;
	std::cout << "Y-intercept: " << y_inter << std::endl << std::endl;

	std::cout << test << std::endl;

}