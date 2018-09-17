// Name: Tai-Juan Rennie	
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 9/13/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#include <cstring>
#include "CString.h"


  int STORED = 3;


namespace w1 {
	CString::CString() : m_MAX(0)
	{
		char * m_STRING = new char[1];
		m_STRING[0] = '/0';
	}

	CString::CString(const char * STRING) : m_MAX(STORED)
	{

		if (strcmp(STRING, "") == 0 || STRING == nullptr)   {



			m_STRING = new char;
			m_STRING[0] = '\0';

		}
		else {

			m_STRING = new char[m_MAX + 1];
			strncpy(m_STRING, STRING, m_MAX);
			m_STRING[m_MAX] = '\0';


		}

	}

	CString::~CString()
	{
		delete[] m_STRING;
	}

	std::ostream & CString::display(std::ostream & os) const
	{

		os << m_STRING;
		return os;
	}




	std::ostream & operator<<(std::ostream & os, const CString& obj)
	{

		static int calls = 0;
		


		os << calls << ": ";
		calls++;

		return obj.display(os);
	}

}


