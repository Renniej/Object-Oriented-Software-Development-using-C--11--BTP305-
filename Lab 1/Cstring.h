#ifndef W1_CSTRING_H
#define W1_CSTRING_H

#include <iostream>

using namespace std;

namespace w1 {


	class CString {

		const int m_NumOfChars = 4; //M
		

	public:
		std::ostream& display(std::ostream& os); //display function
		CString(const char* C_STRING); //constructor

	};


	std::ostream& operator<<(std::ostream& os, const char * C_STRING);



}








#endif
