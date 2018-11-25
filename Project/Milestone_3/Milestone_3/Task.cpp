#include "Task.h"



Task::Task(const std::string & line) : Item(line)
{

	m_pNextTask = nullptr;
	

}

void Task::runProcess(std::ostream & os)
{


	if (!m_orders.empty()) { 

		if (m_orders.back().getItemFillState(Item::getName()) == false) {

			m_orders.back().fillItem(*this, os);

		}
	}

}

void Task::setNextTask(Task & nxt_task)
{

	m_pNextTask = &nxt_task;
}

bool Task::getCompleted(CustomerOrder & cust_order) 
{
	

	//this looks like it would cause issues......
	m_orders.pop_back();
	getCompleted(m_orders.back());

	return m_orders.empty() ? false : true;


}

void Task::validate(std::ostream& os)
{

	os << Item::getName() << " -- > " << ( (m_pNextTask == nullptr) ? "END OF LINE" : m_pNextTask->Item::getName() ) << std::endl;


}

Task & Task::operator+=(CustomerOrder && src)
{
	
	m_orders.push_front(CustomerOrder(std::move(src)));

}

bool Task::moveTask()
{
	if (m_pNextTask != nullptr ) {

		if (!m_orders.empty()) {
			
			if (m_orders.back().getItemFillState(Item::getName()) == true) { //If ItemFillstate is true 

				m_pNextTask->m_orders.push_front(this->m_orders.back());
				m_orders.pop_back();

			}
		}
	}
	else {

		std::cout << "MOVE TASK: " << "m_pNextTask = nullptr " << std::endl;
	}

	return m_orders.empty() ? false : true;
}




Task::Task()
{
	m_pNextTask = nullptr;
}


Task::~Task()
{
}
