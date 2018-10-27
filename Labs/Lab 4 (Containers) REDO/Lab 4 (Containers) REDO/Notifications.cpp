#include "Notifications.h"

#define MAX_MESSAGES 10

namespace w4 {

	void Notifications::SetToEmpty()
	{
		m_Msgs = nullptr;
		m_Num_Of_Messages = 0U;
	}

	void Notifications::Deallocate()
	{
		if (!empty()) {

			for (int i = 0; i < m_Num_Of_Messages; ++i) {
				m_Msgs[i].Deallocate();
			}

		}

		delete[] m_Msgs;
	}

	Notifications::Notifications()
	{
		SetToEmpty();
	}

	Notifications::Notifications(const Notifications & src)
	{
		SetToEmpty();

		*this = src;

	}

	Notifications::Notifications(Notifications && src)
	{
		SetToEmpty();
		*this = std::move(src);
	}


	Notifications::~Notifications()
	{

		Deallocate();

	}

	bool Notifications::empty() const
	{
		return (m_Num_Of_Messages == 0U);
	}

	void Notifications::display(std::ostream & os) const
	{

		if (!empty()) {
			for (int i = 0; i < m_Num_Of_Messages; ++i) {

				m_Msgs[i].display(os);

				if (i != m_Num_Of_Messages-1) {
					os << std::endl;
				}
			}
		}
		else {
			os << "Notification Object is in empty state" << std::endl;
		}

	}

	void Notifications::operator+=(const Message & msg)
	{


		if (m_Num_Of_Messages < MAX_MESSAGES) { //Check if number of max messages exceed limit

			Message * tmp = new Message[m_Num_Of_Messages + 1]; //Create temporary object container to store current messages + spae for incoming message

			for (int i = 0; i < m_Num_Of_Messages; ++i) { //Copy current messsages to current object 

				tmp[i] = m_Msgs[i]; //Call copy assignment Message operator 
				m_Msgs[i].Deallocate(); //After copy assignment deallocate data in m_Msgs;
			}

			tmp[m_Num_Of_Messages] = msg;

			delete[] m_Msgs;

			m_Msgs = tmp;
			tmp = nullptr;

			++m_Num_Of_Messages;

		}

	}




	Notifications & Notifications::operator=(const Notifications & src)
	{
		 
		if (this != &src) {

			Deallocate();
			m_Num_Of_Messages = src.m_Num_Of_Messages;

			m_Msgs = new Message[m_Num_Of_Messages];

			for (int i = 0; i < m_Num_Of_Messages; ++i) {

				m_Msgs[i] = src.m_Msgs[i];

			}


		}


		return *this;
	}
	Notifications & Notifications::operator=(Notifications && src)
	{

		if (this != &src) { //Check that src and this object are the same object
			
			Deallocate(); // Deallocate this object to make sure it s empty

			m_Msgs = src.m_Msgs;




			src.m_Msgs = nullptr;

			m_Num_Of_Messages = src.m_Num_Of_Messages;
			src.m_Num_Of_Messages = 0U;



		}

		return *this;
	}
}