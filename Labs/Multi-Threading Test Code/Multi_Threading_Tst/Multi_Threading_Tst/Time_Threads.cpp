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

void ExecutThread(int id) {

	auto Current_Time = std::chrono::system_clock::now(); //grabs current time in miliseconds

	std::time_t sleepTime = std::chrono::system_clock::to_time_t(Current_Time); //converts time into something readable???

	tm myLocalTime = *localtime(&sleepTime);

	std::cout << "Thread" << id << " Sleep Time : " << std::ctime(&sleepTime) << std::endl;

	//Prints time
	std::cout << "Month : " <<
		myLocalTime.tm_mon << std::endl;
	std::cout <<  "Day : " <<
		myLocalTime.tm_mday << std::endl;
	std::cout << "Year : " << myLocalTime.tm_year << std::endl;
	std::cout << "Hours : " << myLocalTime.tm_hour << std::endl;
	std::cout << "Mintues : " << myLocalTime.tm_min << std::endl;
	std::cout << "Seconds : " << myLocalTime.tm_sec << std::endl << std::endl;


	std::this_thread::sleep_for(std::chrono::seconds(getRandom(3)));
	Current_Time = std::chrono::system_clock::now();
	sleepTime = std::chrono::system_clock::to_time_t(Current_Time);

	std::cout << "Thread" << id << " Awake Time : " << std::ctime(&sleepTime) << std::endl;
}

int main() {

	std::thread th1(ExecutThread, 1);  //executes thread
	
	th1.join(); //tells main thread to wait for th1 to finish executing before countinuing 

	std::thread th2(ExecutThread, 2);

	th2.join();

	return 0;
}
