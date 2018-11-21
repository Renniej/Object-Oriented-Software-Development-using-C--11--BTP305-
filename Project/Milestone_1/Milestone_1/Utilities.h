#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <iostream>

class Utilities
{
	static std::string m_delimiter; // separates the tokens from a given std::string. All Utilities objects share the same delimiter.

	size_t m_widthField; //specifying the length of the token extracted; used for display purpose later; default value is 1.
	

	void setFieldWidth(size_t size);
	size_t getFieldWidth() const;
	const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

	static void setDelimiter(const char c);
public:


	Utilities();
	~Utilities();
};

#endif