#include <algorithm>
#include <fstream>
#include <string>
#include <iterator>     // std::back_inserter
#include "LineManager.h"
#include "Utilities.h"




LineManager::LineManager(const std::string file_name, std::vector<Task*>& Assembly_Line, std::vector<CustomerOrder>& toBeFilled)
{

	m_First_spot = nullptr;

	bool first_line_grabbed = false;
	std::move(toBeFilled.begin(), toBeFilled.end(), std::back_inserter(m_ToBeFilled));
	std::copy(Assembly_Line.begin(), Assembly_Line.end(), std::back_inserter(m_AssemblyLine));

	m_cntCustomerOrder = m_ToBeFilled.size();

	std::ifstream assemb_file(file_name);

	Utilities tmp;


		auto find_Task = [&](std::string Task_name) { //Find Task with matching name and an empty m_next_Task pointer
			Task * task_found = nullptr;

			for (auto& i : m_AssemblyLine) {

				if ((i->getName().compare(Task_name) == 0) && (!i->next_tsk_exist())) {

					task_found = i;
					break;
				}

			}

			return task_found;


		};




	while (assemb_file.good()) {

		bool more = true;
		size_t next_pos = 0;

		std::string line;

		std::getline(assemb_file, line);

		std::string cur_task_name = tmp.extractToken(line, next_pos, more);

		

		while (more) {

		
			Task * cur_task = find_Task(cur_task_name);

			if (first_line_grabbed == false) { //check if ur at the begining of the file.
				m_First_spot = cur_task;
				first_line_grabbed = true;
			}



			//m_AssemblyLine.push_back(cur_task); //Used to determine the order of Tasks


			if (more) {
				std::string next_task_name = tmp.extractToken(line, next_pos, more);
				Task * nxt_task = find_Task(next_task_name);

				//m_AssemblyLine.push_back(nxt_task); //Used to determine the order of Tasks

				cur_task->setNextTask(*nxt_task);
				cur_task_name = next_task_name;
				cur_task = nxt_task;

				
			}
		}
		
	}


	


}

LineManager::LineManager()
{
	m_First_spot = nullptr;
	m_cntCustomerOrder = 0;
}


LineManager::~LineManager()
{
	m_First_spot = nullptr;
}

bool LineManager::run(std::ostream & os) // )': my code is so ugly
{
	
	if (!m_ToBeFilled.empty()) { //If there are incomplete customer orders then.....

		Task * Cur_Task = m_First_spot;

		*Cur_Task += std::move(m_ToBeFilled.front());

		Cur_Task->runProcess(os);
		Cur_Task->moveTask();

		do  {

			Cur_Task = Cur_Task->get_next_Task();

			Cur_Task->runProcess(os);
			Cur_Task->moveTask();

			
		} while (Cur_Task->next_tsk_exist());

		if (!Cur_Task->next_tsk_exist()) { //if u are on last spot of task
			
			CustomerOrder tmp_cust;

			if (!Cur_Task->getCompleted(tmp_cust)) {
				
				m_Completed.push_back(std::move(tmp_cust));
				m_ToBeFilled.pop_front();
			}

		}

	}


	return m_ToBeFilled.empty();

}

void LineManager::displayCompleted(std::ostream & os) const
{


	for (const auto& i : m_Completed) {
		i.display(os);
	}


}

void LineManager::validateTasks() const
{

	for (const auto& i : m_AssemblyLine) {

		i->validate(std::cout);

	}


}



