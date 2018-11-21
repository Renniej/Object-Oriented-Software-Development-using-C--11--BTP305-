#include "Utilities.h"


std::string Utilities::m_delimiter = "|";

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

	if (tmp.length() > next_pos) { //check if next_pos is a valid postion in string first


		tmp = tmp.substr(next_pos); //create substring starting at next_pos

		if (tmp.find(m_delimiter) != std::string::npos) { //If a delimiter exist then extract data, else assume ur are on last part of string line and extract last bit of data

			tmp = tmp.substr(0, tmp.find(m_delimiter));


		}
		
	
		


		//std::cout << "LINE EXTRACTED: " << tmp << std::endl;

		if (tmp.empty()) {
			throw std::string("No data between delimiters!");
		}




		if (m_widthField < tmp.length()) {
			m_widthField = tmp.length();
		}


		next_pos = next_pos + tmp.length() + 1;
		//std::cout << "Next Position changed to : " << next_pos << std::endl;

		more = true;
		


	}
	
	return tmp;


}

void Utilities::setDelimiter(const char c)
{
	
		m_delimiter = c;
	

}



Utilities::Utilities()
{
	setFieldWidth(1);
	//setDelimiter('/n');
}


Utilities::~Utilities()
{
}
