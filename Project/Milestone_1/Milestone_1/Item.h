#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Utilities.h"

class Item
{

	std::string m_name;
	std::string m_description;
	unsigned int m_serialNumber;
	size_t m_quantity;

	static size_t m_widthField; //All Item objects share the same m_widthField

	void setToEmpty();

public:
	Item(const std::string& str);
	Item();
	~Item();

	const std::string& getName() const;
	const unsigned int getSerialNumber();
	const unsigned int getQuantity() const;

	void updateQuantity();
	void display(std::ostream& os, bool full);
};

#endif