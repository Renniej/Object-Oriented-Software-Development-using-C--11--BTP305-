// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 11/22/2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#include "CustomerOrder.h"


size_t CustomerOrder::m_widthField = 1;

void CustomerOrder::SetToEmpty()
{
	m_name = "EMPTY";
	m_product = "EMPTY";
	m_cntItem = -1;
}

CustomerOrder & CustomerOrder::operator=(CustomerOrder && src)
{

	if (this != &src) {
		m_name = std::move(src.m_name);
		m_product = std::move(src.m_product);
		m_cntItem = src.m_cntItem;

		m_lstItem = std::move(src.m_lstItem);
	}

	return *this;
}

CustomerOrder::CustomerOrder(const CustomerOrder & src)
{

	throw std::string("ERROR: Cannot make copies.");


} 

CustomerOrder::CustomerOrder(CustomerOrder && src) noexcept
{
SetToEmpty();
*this = std::move(src); // already checks to make sure if this != &src 
}



CustomerOrder::CustomerOrder()
{
	SetToEmpty();
}

CustomerOrder::CustomerOrder(const std::string & line)
{
	SetToEmpty();
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
				//messy code, fix later
				do  {
					ItemInfo tmp_Item(tmp.extractToken(line, next_pos, more)); //extractToken function needs revising when i have time. It's functional but messy  ):

					
						m_lstItem.push_back(std::move(tmp_Item));
					

				} while (more);

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

bool CustomerOrder::getItemFillState(std::string item_name) const //might be able to code this better
{

	if (item_name.compare("SSD") == 0) {
		//breakpoint
	}


	bool fillstate = true;

	for (auto& i : m_lstItem) {

		if (i.m_itemName.compare(item_name) == 0) {
			fillstate = i.m_fillState;
		}

	}

	return fillstate;


}

bool CustomerOrder::getOrderFillState() const //might be able to code this better
{
	bool All_Filled = true;

	for (auto& i : m_lstItem) {

		if (i.m_fillState == false) {
			All_Filled = false;
			break;
		}

	}

	return All_Filled;


}

void CustomerOrder::fillItem(Item& item, std::ostream& os)
{


	for (auto& i : m_lstItem) {

		if (i.m_itemName.compare(item.getName()) == 0) {

			if (item.getQuantity() > 0) { //Check if item is avaliable in inventory

				item.updateQuantity();
				i.m_serialNumber = item.getSerialNumber();
				i.m_fillState = true;

				os << "Filled " << m_name << ", " << m_product << "[" << item.getName() << "]" << std::endl;

			}
			else {
				os << "Unable to fill " << m_name << ", " << m_product << "[" << item.getName() << "]" << std::endl;
			}
		}
	


	}



}

void CustomerOrder::display(std::ostream & os) const
{

	os << m_name << " - " << m_product << std::endl;


	for (auto& i : m_lstItem) {

		os << "[" << std::setw(6) << std::setfill('0') << std::left << i.m_serialNumber << "] " << std::setfill(' ')
			<< std::setw(m_widthField) << i.m_itemName << " - " << (i.m_fillState ? "FILLED" : "MISSING") << std::endl;
		
	}
}
