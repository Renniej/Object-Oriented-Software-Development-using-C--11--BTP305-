#ifndef SICT_GRADE_H
#define SICT_GRADE_H

#include <fstream>
#include "Letter.h"



namespace sict {

	class Grade
	{
		Letter * Grades;
		float * Stud_IDs;
		size_t Num_Of_Students;

		void SetToEmpty();
		void Deallocate();


	public:

		Grade(const char* Grade_file_name);
		Grade();
		~Grade();

		bool empty() const;
		
		void displayGrades(std::ostream& os);
		
	};

}

#endif