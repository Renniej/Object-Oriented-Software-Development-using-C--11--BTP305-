#include <vector>
#include <deque>
#include "CustomerOrder.h"
#include "Item.h"



class Task : public Item
{

	std::deque<CustomerOrder> m_orders; //Queue of customer orders
	std::shared_ptr<Task> m_pNextTask; //Pointer to next task object (wanted to play around with some smart pointers >:P )

public:

	//Task can not be copied or moved 
	Task(const Task& src) = delete;
	Task(Task&& src) = delete;
	Task& operator=(const Task& src) = delete;
	Task& operator=(Task&& src) = delete;


	Task();
	~Task();
};

