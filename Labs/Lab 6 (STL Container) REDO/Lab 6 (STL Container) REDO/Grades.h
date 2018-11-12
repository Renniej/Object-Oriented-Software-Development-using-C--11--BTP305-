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

		template<typename F>
		void displayGrades(std::ostream& os, F func) {

			for (int i = 0U; i < m_Grades.size(); ++i) {

				os << m_Stud_Nums[i] << " " << m_Grades[i] << " " << func(m_Grades[i]) <<  std::endl; 

			}


		}
	};



}




#endif