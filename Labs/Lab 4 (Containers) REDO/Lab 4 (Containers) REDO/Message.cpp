#include "Message.h"
#pragma warning(disable:4996)

namespace w4 {



	void Message::SetToEmpty()
	{
		
		m_User = nullptr;
		m_Message = nullptr;
		m_Reply = nullptr;
		//std::cout << "Message Object Set To Empty" << std::endl;
	}

	Message::Message()
	{

		//std::cout << "Default Constructor Called" << std::endl;
		SetToEmpty();
	}

	Message::Message(std::ifstream & ifs, char c)
	{

		SetToEmpty();

		if (ifs.good()) {

			std::string Reply_Symbol = "@";

			std::string tmp; //temporary string object to hold single ifs line of content;

			std::getline(ifs, tmp, c); //grab single line of file
				
			std::cout << "Line grabbed from file: " << tmp << std::endl;


			//Grab User Name from line
			size_t UserName_Size = tmp.find(char(32));


			//Check if message is valid
			if (UserName_Size != std::string::npos) {

				m_User = new char[UserName_Size + 1];
				strncpy(m_User, tmp.substr(0, tmp.find(char(32))).c_str(), UserName_Size);
				m_User[UserName_Size] = '\0';

				tmp = tmp.substr(UserName_Size, std::string::npos); //remove Username from the line object



				//Check if the message is being pointed to another user
				size_t found = tmp.find(Reply_Symbol);

				if (found != std::string::npos) {


					tmp = tmp.substr(found + 1, std::string::npos);

					size_t Reply_Size = tmp.find(char(32));

					m_Reply = new char[Reply_Size + 1];
					strncpy(m_Reply, tmp.substr(0, tmp.find(char(32))).c_str(), Reply_Size);
					m_Reply[Reply_Size] = '\0';


					tmp = tmp.substr(Reply_Size, std::string::npos); //remove Reply's username from the line object

				}


				//Store message 
				m_Message = new char[strlen(tmp.c_str()) + 1];
				strncpy(m_Message, tmp.c_str(), strlen(tmp.c_str()));
				m_Message[strlen(tmp.c_str())] = '\0';
			}
		}
	


	}

	Message::~Message()
	{
		delete[] m_User;
		delete[] m_Message;
		delete[] m_Reply;
	}

	bool Message::empty() const
	{
		return (m_User == nullptr);
	}

	void Message::display(std::ostream & os) const
	{


		if (!empty()) {

			os << "Message" << std::endl;
			os << " User : " << m_User << std::endl;

			if (m_Reply != nullptr) {
				os << " Reply : " << m_Reply << std::endl;
			}

			os << " Tweet : " << m_Message << std::endl;



		}

	}
}
