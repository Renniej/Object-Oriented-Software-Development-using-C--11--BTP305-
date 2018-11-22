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
						 //std::cout << "m_Name : " << m_name << std::endl;
					break;
				case 1 :m_serialNumber = std::stoi(tmp.extractToken(str, next_pos, more));
					//std::cout << "m_serialNumber : " << m_serialNumber << std::endl;
					break;
				case 2: m_quantity = std::stoul(tmp.extractToken(str, next_pos, more));
						//std::cout << "m_quantity : " << m_quantity << std::endl;
					break;
				case 3 :m_description = tmp.extractToken(str, next_pos, more);
					//std::cout << "m_description : " << m_description << std::endl;
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

const std::string & Item::getName() const
{
	return m_name;
}

const unsigned int Item::getSerialNumber() 
//returns the next serial number to be used on the assembly line and increments m_serialNumber
{
	return m_serialNumber++;
}

const unsigned int Item::getQuantity() const
{
	return m_quantity;
}

void Item::updateQuantity()
{
	--m_quantity;
}

void Item::display(std::ostream & os, bool full)
{
	//Note: Learn how to format console better.......  (this took me way too long to finish)
	if (full) {


	
	os << std::setw(m_widthField) << std::left << getName();

			
		os <<	"[" << std::setw(6) << std::setfill('0') << std::right << m_serialNumber << "] "  << std::setfill(' ') <<
			
			"Quantity: " <<  std::setw(m_widthField) << std::left << m_quantity  << 
			"Description: " << m_description << std::endl;


	
	}
	else {

		os << std::setw(m_widthField) << std::left << getName() << "[" << m_serialNumber << "]" << std::endl;
	
	}

}

Item::Item()
{
	setToEmpty();
}


Item::~Item()
{
}
