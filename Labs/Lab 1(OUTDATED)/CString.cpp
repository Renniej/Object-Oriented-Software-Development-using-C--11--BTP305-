#include <cstring>
#include "CString.h"

const int STORED = 4;


namespace w1 {

	CString::CString(const char * STRING) :  m_MAX(STORED) {

		if (strcmp(STRING, "") != 0) {

			m_String = new char[ m_MAX];

			strncpy(m_String, STRING,  m_MAX);
			m_String[ m_MAX] = '\0';

		}
		else {
			m_String = new char[1];
			m_String[1] = '\0';
		}

	}

	std::ostream& CString::display(std::ostream& os) const {

		if (strcmp(m_String, "") != 0) {
			os << m_String;
		}
		else {

			os << "CString Object in empty state";
		}

		return os;

	}

	std::ostream& operator<<(std::ostream& os, const char * C_STRING) {

		os << strlen(C_STRING) + 1;
		
		return os;

	}


}