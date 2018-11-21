#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include "Utilities.h"

class Item
{

	std::string m_name;
	std::string m_description;
	std::string m_serialNumber;
	size_t m_quantity;

	static size_t m_widthField; //All Item objects share the same m_widthField

	void setToEmpty();
public:
	Item(const std::string& str);



	Item();
	~Item();
};

#endif