// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 11/22/2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.
#include "Utilities.h"


char Utilities::m_delimiter = '|';

void Utilities::setFieldWidth(size_t size)
{

	m_widthField = size;

}

size_t Utilities::getFieldWidth() const
{
	return m_widthField;
}

const std::string Utilities::extractToken(const std::string & str, size_t & next_pos, bool & more) //sloppy coding, I personally think i can optimize this better....
{
	
	more = false;
	std::string tmp(str); 

	if (tmp.length() > next_pos) { //check if next_pos is a valid postion in string first


		tmp = tmp.substr(next_pos); //create substring starting at next_pos

		if (tmp.find(m_delimiter) != std::string::npos) { //If a delimiter exist then extract data, else assume ur are on last part of string line and extract last bit of data
			
			more = true;

			tmp = tmp.substr(0, tmp.find(m_delimiter));

			if (m_widthField < tmp.length()) {
				//std::cout << "Utility Length : " << m_widthField << " vs. " << "String Length[" << tmp << "] : " << tmp.length() << std::endl;
				m_widthField = tmp.length();
				//std::cout << "Utility Length changed to : " << m_widthField << std::endl << std::endl;
			}

		}
		else {

			tmp = tmp.substr(0, tmp.length());

		}
		
	
		


		//std::cout << "LINE EXTRACTED: " << tmp << std::endl;

		if (tmp.empty()) {
			throw std::string("No data between delimiters!");
		}




		

		next_pos = next_pos + tmp.length() + 1;
		//std::cout << "Next Position changed to : " << next_pos << std::endl;

		
		


	}
	
	return tmp;


}



void Utilities::setDelimiter(const char c)
{
	
		m_delimiter = c;
	

}

const char Utilities::getDelimiter() const
{
	return m_delimiter;
}



Utilities::Utilities()
{
	setFieldWidth(1);
	//setDelimiter('/n');
}


Utilities::~Utilities()
{
}
