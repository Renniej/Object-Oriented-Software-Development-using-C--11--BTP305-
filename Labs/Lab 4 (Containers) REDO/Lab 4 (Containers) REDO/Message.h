// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 10/28/2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#ifndef W4_MESSAGE_H
#define W4_MESSAGE_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

namespace w4 {



	class Message
	{

		char * m_User;
		char * m_Reply;
		char * m_Message;
	

		void SetToEmpty();

	public:
		Message();
		Message(std::ifstream& in, char c);
	
		void Deallocate();

		~Message();


		bool empty() const;

		void display(std::ostream& os) const;
		Message& operator=(const Message& src);
	};

}

#endif