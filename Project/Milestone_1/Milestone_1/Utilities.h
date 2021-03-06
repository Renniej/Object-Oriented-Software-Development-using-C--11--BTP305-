#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <iostream>

class Utilities
{
	static  char m_delimiter; // separates the tokens from a given std::string. All Utilities objects share the same delimiter.

	size_t m_widthField; //specifying the length of the token extracted; used for display purpose later; default value is 1.
	


public:
	

	static void setDelimiter(const char c);
	const char getDelimiter() const;

	void setFieldWidth(size_t size);
	size_t getFieldWidth() const;
	const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);



	Utilities();
	~Utilities();
};

#endif