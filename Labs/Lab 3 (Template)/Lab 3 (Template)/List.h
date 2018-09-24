// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172	
// Seneca email: Trennie1@myseneca.ca
// Date of completion: 9/21/108
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#ifndef LIST_H
#define LIST_H

template <typename T, int N>

class List {

	T m_Array[N];  
	size_t m_Array_size;
	size_t m_filled; //Number of spaces filled in array

public:
	List() : m_Array_size(N), m_filled(0) {}

	size_t size() const { return m_Array_size; }

	const T& operator[](int index) const { return m_Array[index]; }


	void operator+=(const T& param) {


		if (m_filled < m_Array_size) { // -1U is in case we 

			m_Array[m_filled++] = param;
			

		}
	}


	
};






#endif