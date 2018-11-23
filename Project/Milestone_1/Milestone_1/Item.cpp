// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 11/22/2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.
#include "Item.h"


size_t Item::m_widthField = 1;

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
			if (tmp.getFieldWidth() > m_widthField) {

				//std::cout << "Item m_width : " << m_widthField << std::endl;
				//std::cout << "Utility m_width : " << tmp.getFieldWidth() << std::endl;
				//std::cout << "Item m_width changed to : " << tmp.getFieldWidth() << std::endl << std::endl;

				
				m_widthField = tmp.getFieldWidth();
			}

		}
		else {
			break;
		}

		
	}

	if (tmp.getFieldWidth() > m_widthField) {

		/*std::cout << "Item m_width : " << m_widthField << std::endl;
		std::cout << "Utility m_width : " << tmp.getFieldWidth() << std::endl;
		std::cout  << "Item m_width changed to : " << tmp.getFieldWidth() << std::endl << std::endl;*/

		m_widthField = tmp.getFieldWidth();
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
	
	
	
	os << std::setw(m_widthField) << std::left << getName();
	os  << " [" << std::setw(6) << std::setfill('0') << std::right << m_serialNumber << "]" << std::setfill(' ');
	
	full ? os << " Quantity: " << std::setw(m_widthField) << std::left << m_quantity <<
	" Description: " << m_description << std::endl : os << std::endl;


}

Item::Item()
{
	setToEmpty();
}


Item::~Item()
{
}
