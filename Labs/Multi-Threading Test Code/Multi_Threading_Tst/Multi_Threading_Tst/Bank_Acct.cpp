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


double acctBalance = 100;

std::mutex acctLock; //stops threads from accessing the same data at the same time

int getRandom(int max) {

	srand(time(NULL));

	return rand() % max;  //random number can not exceed max
}


std::string GetTime() {

	auto Current_Time = std::chrono::system_clock::now(); //grabs current time in miliseconds
	std::time_t sleepTime = std::chrono::system_clock::to_time_t(Current_Time); //converts time into something readable???

	return std::ctime(&sleepTime);


}

void GetMoney(int id, double withdrawl) {

	std::lock_guard<std::mutex> lock(acctLock); //restricts access to function once one thread executes this function
	std::this_thread::sleep_for(std::chrono::seconds(3));

	std::cout << id <<
		" tries to withdrawl $" << withdrawl << " on " << GetTime();

	if ((acctBalance - withdrawl) >= 0) {
		acctBalance -= withdrawl;

		std::cout << "New Account Balance is $" << acctBalance << std::endl;
	}
	else {

		std::cout << "Not Enough Money in Account" << std::endl;
		std::cout << "Current Balance is $" << acctBalance << std::endl;

	}

}




int main() {

	std::thread threads[10]; 

	for (int i = 0; i < 10; ++i) {
		threads[i] = std::thread(GetMoney, i, 15);
	}

	//wait for these threads to finish before going forward
	for (int i = 0; i < 10; ++i) {
		threads[i].join();
	} 



	return 0;
}