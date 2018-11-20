#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <thread>
#include <chrono>
#include <ctime>
#include <mutex>


int getRandom(int max) {

	srand(time(NULL));

	return rand() % max;  //random number can not exceed max
}


std::string GetTime() {

	auto Current_Time = std::chrono::system_clock::now(); //grabs current time in miliseconds
	std::time_t sleepTime = std::chrono::system_clock::to_time_t(Current_Time); //converts time into something readable???

	return std::ctime(&sleepTime);

}


void FindPrimes(unsigned int start, unsigned int end, std::vector<unsigned int>& vect) {

	for (unsigned int x = start; x <= end; x += 2) {

		for (unsigned int y = 2; y < x; y++) {

			if ((x%y) == 0) {
				break;
			}
			else if ((y + 1) == x) {
				vect.push_back(x);
			}
		}


	}


}

int main() {


	std::vector<unsigned int> primeVect;
	int startTime = clock();
	FindPrimes(1, 100000, primeVect);

	for (auto i : primeVect) {

		std::cout << i << std::endl;
	}


	int endTime = clock();

	std::cout << "Execution Time : " << (endTime - startTime) / double(CLOCKS_PER_SEC) << std::endl;

	return 0;

}