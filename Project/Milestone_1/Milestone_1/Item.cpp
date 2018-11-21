#include "Item.h"


size_t Item::m_widthField = 0;

void Item::setToEmpty()
{
	m_quantity = 0;

}

Item::Item(const std::string & str)
{
	setToEmpty();

	Utilities tmp;

	bool more = true;
	size_t next_pos = 0;

	for (int i = 0; i < 4; ++i) {

		if (more) {

			switch (i) {

				case 0 : m_name = tmp.extractToken(str, next_pos, more);
						 std::cout << "m_Name : " << m_name << std::endl;
					break;
				case 1 :m_serialNumber = tmp.extractToken(str, next_pos, more);
					std::cout << "m_serialNumber : " << m_serialNumber << std::endl;
					break;
				case 2: m_quantity = std::stoul(tmp.extractToken(str, next_pos, more));
						std::cout << "m_quantity : " << m_quantity << std::endl;
					break;
				case 3 :m_description = tmp.extractToken(str, next_pos, more);
					std::cout << "m_description : " << m_description << std::endl;
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

Item::Item()
{
	setToEmpty();
}


Item::~Item()
{
}
