#include <fstream>
#include <string>
#include <cstring>

#include "Grades.h"


namespace sict {

	Grades::Grades()
	{
	}

	Grades::Grades(std::string filename)
	{


		std::ifstream file(filename);

		if (file.is_open()) {

			std::string line;

			while (file.good()) {


				std::getline(file, line);
				
				m_Stud_Nums.push_back(line.substr(0, line.find(" "))); //Grab Student NUmber and push to Stud_Nums vector
				m_Grades.push_back( std::stod(line.substr(line.find(" ") + 1, line.back()) )); //Grade Grade and convert to double then push to Grades vector


			}





		}
		else {
			throw "File did not open";
		}

	}

	Grades::~Grades()
	{
	}
}