#include <fstream>
#include <string>
#include "Grade.h"


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

				m_Stud_Nums.push_back("HELLO");



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