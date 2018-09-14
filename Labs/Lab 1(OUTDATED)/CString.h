// Name: Tai-Juan Rennie
// Seneca Student ID: 
// Seneca email: trennie1@myseneca.ca
// Date of completion:
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#ifndef W1_CSTRING_H
#define W1_CSTRING_H

#include <iostream>

using namespace std;




namespace w1 {

	class CString {

		const int m_MAX; //Max characters
		char* m_String;

	public:
		std::ostream& display(std::ostream& os) const; //display function
		CString(const char* C_STRING); //constructor
	};

	
	std::ostream& operator<<(std::ostream& os, const char * C_STRING);



}








#endif
