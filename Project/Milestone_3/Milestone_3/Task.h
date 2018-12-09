#ifndef TASK_H
#define TASK_H

#include <vector>
#include <deque>
#include "CustomerOrder.h"
#include "Item.h"



class Task : public Item
{

	std::deque<CustomerOrder> m_orders; //Queue of customer orders
	Task * m_pNextTask; //Pointer to next task object (wanted to play around with some smart pointers >:P )

public:

	//Task can not be copied or moved 
	Task(const Task& src) = delete;
	Task(Task&& src) = delete;
	Task& operator=(const Task& src) = delete;
	Task& operator=(Task&& src) = delete;


	Task(const std::string& line);

	void runProcess(std::ostream& os);
	bool moveTask();
	void setNextTask(Task& nxt_task);
	bool getCompleted(CustomerOrder& cust_order); //This function might cause issues.....

	void validate(std::ostream& os);
	bool next_tsk_exist() const;
	Task * get_next_Task() const;
	Task& operator+=(CustomerOrder&& src);

	Task();
	~Task();
};

#endif