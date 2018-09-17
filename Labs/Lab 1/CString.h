// Name: Tai-Juan Rennie	
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 9/13/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W1_CSTRING_H
#define W1_CSTRING_H

#include <iostream>


namespace w1 {

	class CString {

		const int m_MAX;
		char * m_STRING;


		public:


			CString();
			CString(const char * STRING);
			~CString();

		
			std::ostream& display(std::ostream& os) const;


	};
	


	std::ostream& operator<<(std::ostream& os, const CString& tmp);




}

#endif