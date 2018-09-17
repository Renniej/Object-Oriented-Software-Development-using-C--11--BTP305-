// Name: Tai-Juan Rennie	
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 9/13/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.



// Workshop 1 - Linkage, Storage Duration, Namespaces,
// and OS Interface
// w1.cpp
// Author: Dr. Elliott Coleshill
// Date: 2018-08-22

#include <iostream>
#include <fstream>
#include "process.h"

using namespace std;

extern int STORED;

int main(int argc, char* argv[])
{
	cout << "Command Line: ";

	for (int i = 0; i < argc; i++)
	{
		cout << argv[i] << ' ';
	}

	if (argc < 2)
	{
		cout << "\nInsufficient number of arguments\n";
		return 1;
	}


	std::cout << std::endl << "Maximum number of characters stored: " << STORED << std::endl;


	for (int i = 1; i < argc; i++)
	{
		process(argv[i], cout);
	}

	return 0;
}