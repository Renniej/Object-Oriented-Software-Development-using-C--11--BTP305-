#include <fstream>
#include <istream>
#include "Message.h"
namespace w4 {

	

	Message::Message()
	{
		SetToEmpty();
	}

	Message::Message(std::ifstream& in, char c)
	{

		if (in.is_open) {

			m_User = nullptr;
			in.getline(m_User, 1, c);
			
		

			m_Message = nullptr;
			in.getline(m_Message, 1, c);
		}
		else {
			SetToEmpty();
		}



	}


	Message::~Message()
	{
		delete[] m_Message;
	}

	bool Message::empty() const
	{
		return (strcmp("Empty", m_User) == 0);
	}

	void Message::display(std::ostream &) const
	{

		if (!empty()) {


			std::cout << "User : " << m_User << std::endl;
			std::cout << "Tweet : " << m_Message << std::endl;
		}
		else {
			std::cout << "OBJECT IN EMPTY STATE" << std::endl;
		}
	}

	void Message::SetToEmpty()
	{
		m_User = new char[9];
		m_User = (char*)"Empty";
		m_Message = nullptr;
	
	}

}