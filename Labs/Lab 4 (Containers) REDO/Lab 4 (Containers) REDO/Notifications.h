// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 10/28/2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.


#ifndef W4_NOTIFICATIONS_H
#define W4_NOTIFICATIONS_H

#include "Message.h"

namespace w4 {
	class Notifications
	{

		Message * m_Msgs;
		std::size_t m_Num_Of_Messages;

		void SetToEmpty();
		void Deallocate();
	public:
		Notifications();
		Notifications(const Notifications& src );
		Notifications(Notifications&& src);
		~Notifications();

		bool empty() const;
		void display(std::ostream& os) const;
		

		void operator+=(const Message& msg);
	
		Notifications& operator=(const Notifications& src);
		Notifications& operator=(Notifications&& src);
	};

}

#endif