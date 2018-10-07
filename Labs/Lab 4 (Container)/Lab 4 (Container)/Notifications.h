#include "Message.h"




namespace w4 {
	class Notifications
	{

		Message * m_msgs;
		size_t m_Num_Of_Msgs;

		void SetToEmpty();

	public:
		Notifications();
		~Notifications();
		Notifications(const Notifications& src);
		Notifications(Notifications&& src);


		bool empty() const;
		void operator=( Notifications&& src);
		void operator=(const Notifications& src);
		void operator+=(const Message& msg);
		void display(std::ostream os) const;

	};

}