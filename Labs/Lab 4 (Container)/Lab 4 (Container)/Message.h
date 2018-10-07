#ifndef w4_MESSAGE_H
#define w4_MESSAGE_H

#include <iostream>
#include <string>
#include <fstream>
#include <istream>

namespace w4 {

	class Message
	{
		char *m_User;
		char* m_Message;

		void SetToEmpty();  //sets object to empty state

	public:
		Message();
		Message(std::ifstream& in, char c);
		Message(const Message&);
		Message(Message&&);
	

		Message& operator=(const Message&);
		Message& operator=(Message&&);


		~Message();


		bool empty() const;

		void display(std::ostream&) const;
		void testContents() const;
	};
}

#endif
