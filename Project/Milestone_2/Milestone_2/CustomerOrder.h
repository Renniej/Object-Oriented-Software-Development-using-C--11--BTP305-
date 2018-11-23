#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H


// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 11/22/2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.


#include <string>
#include <vector>
#include "Utilities.h"
#include "Item.h"

struct ItemInfo
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_fillState = false;

	ItemInfo(std::string src) : m_itemName(src) {};
};


class CustomerOrder
{

	std::string m_name;
	std::string m_product;
	unsigned int m_cntItem;

	std::vector<ItemInfo> m_lstItem;
	static size_t m_widthField;
	void SetToEmpty();
public:
	CustomerOrder& operator=(const CustomerOrder& cust) = delete;
	CustomerOrder& operator=(CustomerOrder&& src);


	CustomerOrder(const CustomerOrder& src);
	 CustomerOrder(CustomerOrder&& src) noexcept;

	CustomerOrder();
	CustomerOrder(const std::string& line);
	~CustomerOrder();

	bool getItemFillState(std::string item_name) const;
	bool getOrderFillState() const;
	void fillItem(Item& item, std::ostream&);
	void display(std::ostream& os) const;
};

#endif