#ifndef LINEMANAGER_H
#define LINEMANAGER_H

#include <vector>
#include "Task.h"

class LineManager
{
	std::vector<Task*> m_AssemblyLine; //A container containing all the references of the Task objects on the assembly line
	std::deque<CustomerOrder> m_ToBeFilled; //A queue of customer orders to be filled
	std::deque<CustomerOrder> m_Completed; //A queue of customer orders completed

	Task * m_First_spot;
	Task * m_Last_spot;

	unsigned int m_cntCustomerOrder; // The number of CustomerOrder objects the assembly line started with.


public:
	LineManager(const std::string file_name, std::vector<Task*>& Assembly_Line, std::vector<CustomerOrder>& toBeFilled);
	LineManager();
	~LineManager(); //remembler to deallocate m_AssemblyLine


	bool run(std::ostream& os);
	void displayCompleted(std::ostream& os) const;
	void validateTasks() const;
};

#endif