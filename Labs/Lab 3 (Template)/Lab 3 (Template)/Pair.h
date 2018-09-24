// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172	
// Seneca email: Trennie1@myseneca.ca
// Date of completion: 9/21/108
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#ifndef PAIR_H
#define PAIR_H



 //template <typename A, typename B>

class Pair {
	
	int m_a;
	int m_b;
	bool m_Safe_State; //dictates if object is in empty state

	Pair() :m_Safe_State(true) {}

	Pair(const int& a, const int& b) : m_Safe_State(false){

		m_a = a;  m_b = b;
	}

	const int& getKey() const {
		return m_a;
	}

	const int& getValue() const {

		return m_b;

	}

};


#endif
