#include <cstring>
#include "Message.h"

using namespace std;

namespace w4 {

	

	Message::Message()
	{
		SetToEmpty();
	}

	Message::Message(std::ifstream& ifs, char c)
	{

		if (ifs.good()) { //if file is good then prepare message object for input

			m_User = nullptr;
			m_Message = nullptr;

			std::string tmp;  //a tempory string is created to hold a getline from the file

			std::getline(ifs, tmp);  // a line is grabbed from the file and stored in a string for modification



			m_User = new char[tmp.find(char(32)) + 1];   //dynamic memory is allocated for all chars up to the first 'space' char a.k.a char(32) which represents the User
			strcpy(m_User, tmp.substr(0, tmp.find(char(32))).c_str());  //once allocated the  all chars up to the first 'space' char a.k.a char(32) which represents the User
																		// is copied into the object


			if (strlen(m_User) == tmp.length()) {
				SetToEmpty();
			}
			else {
				m_Message = new char[tmp.length() - tmp.find(char(32))];  //Same thing as above but in this case we specifically copy all the text after the first space which represents the emssage
				strcpy(m_Message, tmp.substr(tmp.find(char(32)), tmp.length()).c_str()); //self-explaintory
			}
	
		}
		else { //else set message object to empty state;
			SetToEmpty();
		}



	}

	Message::Message(const Message & src)
	{

		m_User = nullptr;
		m_Message = nullptr;

		*this = src;

	}

	Message::Message(Message && src)
	{

		*this = std::move(src);
	}


	Message & Message::operator=(const Message&  src)
	{

		delete[] m_User;
		m_User = nullptr;

		m_User = new char[strlen(src.m_User) + 1];
		strcpy(m_User, src.m_User);


		delete[] m_Message;
		m_Message = nullptr;

		m_Message = new char[strlen(src.m_Message) + 1];
		strcpy(m_Message, src.m_Message);

		return *this;

	}

	Message & Message::operator=(Message && src)
	{
			
		delete[] m_User;
		delete[] m_Message;

		m_User = nullptr;
		m_Message = nullptr;

		m_User = src.m_User;
		src.m_User = nullptr;

		m_Message = src.m_Message;
		src.m_Message = nullptr;

		return *this;
			
	}

	Message::~Message()
	{
	
	}

	bool Message::empty() const
	{
		return (strcmp("Empty", m_User) == 0);
	}

	void Message::display(std::ostream& os) const
	{

		if (!empty()) {
			os << "User : " << m_User << std::endl;
			os << "Tweet : " << m_Message << std::endl;
		}
		else {
			os << "OBJECT IN EMPTY STATE" << std::endl;
		}


	}


	void Message::testContents() const //ignore, just a function used for testing
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
		//std::cout << (m_User);
		m_Message = nullptr;
	
	}

}