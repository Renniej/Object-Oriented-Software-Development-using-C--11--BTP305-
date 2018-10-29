#include <string>
#include <iostream>
#include <fstream>
#include "Grade.h"

namespace sict {

	void sict::Grade::SetToEmpty()
	{
		Grades = nullptr;
		Stud_IDs = nullptr;
		Num_Of_Students = 0U;
	}

	void Grade::Deallocate()
	{
		delete[] Grades;
		Grades = nullptr;
		delete[] Stud_IDs;
		Stud_IDs = nullptr;

	}



	Grade::Grade(const char* Grade_file_name)
	{

		SetToEmpty();

		std::ifstream file;

		try
		{
			
			file.open(Grade_file_name);
		}
		catch (...)
		{
			throw "File failed to open";
		}


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