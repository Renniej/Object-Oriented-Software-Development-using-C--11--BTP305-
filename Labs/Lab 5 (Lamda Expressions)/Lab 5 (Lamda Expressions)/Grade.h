#ifndef SICT_GRADE_H
#define SICT_GRADE_H

#include <fstream>
#include "Letter.h"



namespace sict {

	class Grade
	{
		Letter * Grades;
		float * Stud_IDs;

		void SetToEmpty();
		void Deallocate();


	public:

		Grade(std::ifstream os);
		Grade();
		~Grade();

		bool empty() const;
		
		void displayGrades(std::ostream& os);
		
	};

}

#endif