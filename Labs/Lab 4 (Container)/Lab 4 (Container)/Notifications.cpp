#include "Notifications.h"

const int MAX_MESSAGES = 10;

namespace w4 {

	void Notifications::SetToEmpty() {

		m_msgs = nullptr;
		m_Num_Of_Msgs = 0U;
	}

	Notifications::Notifications()
	{
		SetToEmpty();
	}


	Notifications::~Notifications()
	{

		delete[] m_msgs;
	}

	Notifications::Notifications(const Notifications & src)
	{

		*this = src;
	}

	Notifications::Notifications(Notifications && src)
	{

		*this = std::move(src);

	}





	void Notifications::operator=(const Notifications & src)
	{

		delete[] m_msgs;
		m_msgs = nullptr;

		
		m_Num_Of_Msgs = src.m_Num_Of_Msgs;
		m_msgs = new Message[src.m_Num_Of_Msgs];

		for (size_t i = 0U; i < src.m_Num_Of_Msgs; ++i) {

			m_msgs[i] = src.m_msgs[i];

		}


	}
	bool Notifications::empty() const
	{
		return (m_Num_Of_Msgs == 0U);
	}

	void Notifications::operator=( Notifications && src)
	{
		m_Num_Of_Msgs = src.m_Num_Of_Msgs;
		m_msgs = src.m_msgs;
		src.m_msgs = nullptr;


	}

	void Notifications::operator+=(const Message & msg)
	{

		if (m_Num_Of_Msgs != MAX_MESSAGES) {

			if (!msg.empty()) {

				Message* tmp_msgs = new Message[m_Num_Of_Msgs + 1];
				
				for (size_t i = 0U; i < m_Num_Of_Msgs; ++i) {

					tmp_msgs[i] = std::move(m_msgs[i]);

				}

				tmp_msgs[++m_Num_Of_Msgs] = msg;

				m_msgs = tmp_msgs;
				tmp_msgs = nullptr;


			}

		}


	}
	void Notifications::display(std::ostream os) const
	{

		os << "Notifications" << std::endl << "=============" << std::endl << std::endl;

		for (size_t i = 0u; i < m_Num_Of_Msgs; ++i) {

			m_msgs[i].display(os);
		}

	}
}