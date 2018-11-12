#ifndef SICT_GRADE_H
#define SICT_GRADE_H

#include <vector>
#include <string>
#include "Letter.h"

namespace sict {



	class Grades {

		std::vector<double> m_Grades;
		std::vector<std::string> m_Stud_Nums;


	public:
		
		Grades();
		Grades(std::string filename);

		~Grades();
	};



}




#endif