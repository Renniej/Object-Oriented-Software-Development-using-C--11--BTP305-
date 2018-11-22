#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H
#include <string>
#include <vector>
#include "Utilities.h"


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

public:
	CustomerOrder();
	CustomerOrder(const std::string& line);
	~CustomerOrder();
};

#endif