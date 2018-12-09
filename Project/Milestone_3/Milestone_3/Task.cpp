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
	//std::cout << "setNextTask Called: " << Item::getName() << "--->" << nxt_task.Item::getName() << std::endl;
	m_pNextTask = &nxt_task;
}

bool Task::getCompleted(CustomerOrder & cust_order) //this looks like it would cause issues......
{
	
	if (!m_orders.empty() && m_orders.back().getOrderFillState()) {
		cust_order = std::move(m_orders.back());
		m_orders.pop_back();
	}

	return m_orders.empty() ? false : true;


}

void Task::validate(std::ostream& os)
{

	os << Item::getName() << " -- > " << ( (m_pNextTask == nullptr) ? "END OF LINE" : m_pNextTask->Item::getName() ) << std::endl;


}

bool Task::next_tsk_exist() const
{
	return m_pNextTask != nullptr;
}

Task * Task::get_next_Task() const
{
	return m_pNextTask;
}

Task & Task::operator+=(CustomerOrder && src)
{
	
	m_orders.push_front(CustomerOrder(std::move(src)));

	return *this;
}

bool Task::moveTask()
{
	if (m_pNextTask != nullptr ) {

		if (!m_orders.empty()) {
			
			if (m_orders.back().getItemFillState(Item::getName()) == true) { //If ItemFillstate is true 

				m_pNextTask->m_orders.push_front(std::move(this->m_orders.back()));
				m_orders.pop_back();

			}
		}
	}
	/*else {

		//std::cout << "MOVE TASK: " << "m_pNextTask = nullptr " << std::endl;
	} */

	return m_orders.empty() ? false : true;
}




Task::Task()
{
	m_pNextTask = nullptr;
}


Task::~Task()
{
}
