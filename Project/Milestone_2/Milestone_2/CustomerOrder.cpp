#include "CustomerOrder.h"



CustomerOrder::CustomerOrder()
{
}

CustomerOrder::CustomerOrder(const std::string & line)
{

	Utilities tmp;
	bool more = true;
	size_t next_pos = 0;
	

	for (int i = 0; i < 3; ++i) {

		if (more) {

			switch (i) {

			case 0: m_name = tmp.extractToken(line, next_pos, more);
				//std::cout << "m_Name : " << m_name << std::endl;
				break;
			case 1: m_product = tmp.extractToken(line, next_pos, more);
				//std::cout << "m_product : " << m_serialNumber << std::endl;
				break;
			case 2:  //At this point there is only Iteminfo objects
				while (more) { 

					m_lstItem.push_back(ItemInfo(tmp.extractToken(line, next_pos, more)));
				 }
				break;
			}

		}
		else {
			break;
		}

		if (tmp.getFieldWidth() > m_widthField) {
			m_widthField = tmp.getFieldWidth();
		}

	}

}


CustomerOrder::~CustomerOrder()
{
}
