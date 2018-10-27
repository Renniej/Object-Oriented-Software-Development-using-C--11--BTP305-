#include "Grade.h"

namespace sict {

	void sict::Grade::SetToEmpty()
	{
		Grades = nullptr;
		Stud_IDs = nullptr;
	}

	void Grade::Deallocate()
	{
		delete[] Grades;
		Grades = nullptr;
		delete[] Stud_IDs;
		Stud_IDs = nullptr;

	}



	Grade::Grade()
	{

		SetToEmpty();

	}


	Grade::~Grade()
	{
		Deallocate();
	}

	bool Grade::empty() const
	{
		return (Grades == nullptr);
	}

}