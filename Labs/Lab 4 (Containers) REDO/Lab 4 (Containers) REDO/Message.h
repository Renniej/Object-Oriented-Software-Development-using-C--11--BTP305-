#ifndef W4_MESSAGE_H
#define W4_MESSAGE_H

#include <iostream>
#include <fstream>
#include <string>

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