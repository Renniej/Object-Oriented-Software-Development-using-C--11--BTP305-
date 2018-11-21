#ifndef ITEM_H
#define ITEM_H


#include <string>

class Item
{

	std::string m_name;
	std::string m_description;
	std::string m_serialNumber;
	size_t m_quantity;

	static size_t m_widthField; //All Item objects share the same m_widthField

public:
	Item();
	~Item();
};

#endif