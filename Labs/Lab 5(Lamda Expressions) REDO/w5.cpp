// Workshop 5 - Lambda Expression
// 345_w5.cpp
// Chris Szalwinski & Dr. Elliott Coleshill
// 2018-08-22

#include <iostream>
#include "Grades.h"
#include "Letter.h"

using namespace sict;

int main(int argc, char* argv[]) {

	std::cout << "Command Line: ";
	for (int i = 0; i < argc; i++)
		std::cout << argv[i] << ' ';
	std::cout << std::endl;

	if (argc == 1) {
		std::cerr << "\n*** Insufficient number of arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 1;
	}
	else if (argc != 2) {
		std::cerr << "\n*** Too many arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 2;
	}

	//TODO: Update the main functions as per the specifications here
	Grades grades(argv[1]);

	auto letter = [](double Stud_Grade) {

		char * Letter_Grade = nullptr;

		if (Stud_Grade >= 90 && Stud_Grade <= 100) {
			Letter_Grade = &ToString(Ap);
		}
		else if (Stud_Grade >= 80 && Stud_Grade <= 89) {
			Letter_Grade = &ToString(A);
		}
		else if (Stud_Grade >= 75 && Stud_Grade < 80) {
			Letter_Grade = &ToString(Bp);
		}
		else if (Stud_Grade >= 70 && Stud_Grade < 75) {
			Letter_Grade = &ToString(B);
		}
		else if (Stud_Grade >= 65 && Stud_Grade < 70) {
			Letter_Grade = &ToString(Cp);
		}
		else if (Stud_Grade >= 60 && Stud_Grade < 65) {
			Letter_Grade = &ToString(C);
		}
		else if (Stud_Grade >= 55 && Stud_Grade < 60) {
			Letter_Grade = &ToString(Dp);
		}

		else if (Stud_Grade >= 50 && Stud_Grade < 55) {
			Letter_Grade = &ToString(D);

		}
		else if (Stud_Grade >= 0 && Stud_Grade < 50) {
			Letter_Grade = &ToString(Fa);
		}
		else {
			Letter_Grade = &ToString(30); //should return E
		}

		return Letter_Grade;

	};

	grades.displayGrades(std::cout, letter);

	return 0;
}