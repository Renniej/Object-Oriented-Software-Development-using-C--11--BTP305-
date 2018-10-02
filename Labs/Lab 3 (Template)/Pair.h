// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172	
// Seneca email: Trennie1@myseneca.ca
// Date of completion: 9/21/108
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#ifndef PAIR_H
#define PAIR_H



 template <typename A, typename B>

class Pair {
	
	A m_a;
	B m_b;
	

public:
	Pair() {} //how do u set a template class to empty safe state???????????

	Pair(const A& a, const B& b){

		m_a = a;  m_b = b;
	}

	const A& getKey() const {
		return m_a;
	}

	const B& getValue() const {

		return m_b;

	}

};


#endif
