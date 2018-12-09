#ifndef SICT_LETTER_H
#define SICT_LETTER_H

#include <cstring>

namespace sict {

	enum Letter { A, Ap, B, Bp, C, Cp, D, Dp, Fa };



	template<typename F> // Why template? IDK? Ask prof later
	char& ToString(const F& letter) {
			
		char *  grade = new char[3];

		switch (letter) {

			case Ap : strcpy(grade, "A+");
				break;
			case A : strcpy(grade, "A");
				break;
			case Bp : strcpy(grade, "B+");
				break;
			case B : strcpy(grade, "B");
				break;
			case Cp: strcpy(grade, "C+");
				break;
			case Dp : strcpy(grade, "D+");
				break;
			case D: strcpy(grade, "D");
				break;
			case Fa : strcpy(grade, "F");
				break;
			default: strcpy(grade, "E");
				break;
		}

		return *grade;

	};

}

#endif