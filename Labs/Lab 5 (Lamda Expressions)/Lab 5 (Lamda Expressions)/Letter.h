#ifndef SICT_LETTER_H
#define SICT_LETTER_H


namespace sict {

	enum Letter { A, Ap, B, Bp, C, Cp, D, Dp, F };



	template<typename Letter> // Why template? IDK? Ask prof later


	char& ToString(const Letter& letter) {
			
		char *  grade = new char[3];

		switch (letter) {

			case Ap : strcpy(grade, "A+");

			case A : strcpy(grade, "A");

			case Bp : strcpy(grade, "B+");

			case B : strcpy(grade, "B");
			
			case Cp: strcpy(grade, "C+");

			case Dp : strcpy(grade, "D+");

			case F : strcpy(grade, "F");

			default: strcpy(grade, "E");

		}

		return *grade;

	};

}

#endif