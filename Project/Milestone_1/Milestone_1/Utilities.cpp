#include "Utilities.h"


std::string Utilities::m_delimiter = "D";

void Utilities::setFieldWidth(size_t size)
{

	m_widthField = size;

}

size_t Utilities::getFieldWidth() const
{
	return m_widthField;
}

const std::string Utilities::extractToken(const std::string & str, size_t & next_pos, bool & more)
{
	
	more = false;
	std::string tmp(str);

	if (tmp.length() < next_pos) { //check if next_pos is a valid postion in string first

		tmp = tmp.substr(next_pos); //create substring starting at next_pos

		if (tmp.find(m_delimiter) != std::string::npos) {

			tmp = tmp.substr(0, tmp.find(m_delimiter));  //Grab token from string

			std::cout << "LINE EXTRACTED: " << tmp << std::endl;

			if (tmp.empty()) {
				throw "No data between delimiters!";
			}
			
				
		

			if (m_widthField < tmp.length()) {
				m_widthField = tmp.length();
			}

			more = true;


		}


	}
	



}

void Utilities::setDelimiter(const char c)
{
	
		m_delimiter = c;
	

}



Utilities::Utilities()
{
	setFieldWidth(1);
	setDelimiter('/n');
}


Utilities::~Utilities()
{
}
