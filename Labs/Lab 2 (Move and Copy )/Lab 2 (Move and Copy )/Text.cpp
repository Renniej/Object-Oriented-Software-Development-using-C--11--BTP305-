// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 9/19/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include <cstring>
#include "Text.h"


namespace w2 {

	void Text::SetToEmpty()// Sets object to empty
	{

		m_File_Name = "Empty_State";
		m_Text = nullptr;
		m_Line_Count = 0U;

	}

	size_t Text::size() const  //retrives number of lines in file
	{
		return m_Line_Count;
	}

	Text::Text()  //default constructor that sets text object toe mpty state
	{
	
		SetToEmpty();

	}

	Text::Text(const string & name)
	{

		//1. Check if file exist
		//2. If file exist check how many lines are in the file
		//3. Once you know the number of lines create Text Objects to hold each line (Array?)

		std::ifstream file(name);



		if (file.is_open()) { // If file exist then begin filling out current Text Object
			
			
			//std::cout << "FILE FOUND" << std::endl;

			m_File_Name = name;

			m_Line_Count = 0U;
			string tmp;

			while (!file.eof()) {
				getline(file, tmp);
				m_Line_Count++;
			}

			//std::cout << "Number of lines: " << m_Line_Count << std::endl;

			m_Text = new string[m_Line_Count]; //Dynamically allocate memory for number of lines in file


			

			//At this point the EOF flag is set due to me scanning for the number of lines above.
			//We need to clear the EOF flag and then point the stream back to the first line of file.

			file.clear(); //Clears EOF flag
			file.seekg(0, ios::beg); //Point stream to first line of file


			for (size_t i = 0U; i < m_Line_Count; ++i) { //Now scan file again and input each line into a string object
				getline(file, m_Text[i]);
				//std::cout << m_Text[i] << std::endl;
			}

			file.close();

		}

		else { //else  set Text Object to empty state 

			//std::cout << "FILE NOT FOUND" << std::endl;

			SetToEmpty();
		}

	}

	Text::Text(const Text & source) //Copy Constructor
	{

		*this = source; //uses overloaded = copy operator 
	}

	Text::Text(Text && source) //Move Constructor
	{
		//std::cout << "MOVE CONSTUCTOR" << std::endl;

		// uses overloaded  = move operator
		//std::move(source) forces 
		*this = std::move(source); 
		


	}







	Text& Text::operator=(const Text& source) //Copy
	{
		if (this != &source) {  //check that we are not copying to ourselves

			m_File_Name = source.m_File_Name;
			m_Line_Count = source.m_Line_Count;

			delete[] m_Text; //delete currently dynamically allocated memory

			m_Text = new string[m_Line_Count]; //dynamically allocate new memory for copy

			for (size_t i = 0U; i < m_Line_Count; ++i) {  //copy memory of source to current text object's m_Text
				m_Text[i] = source.m_Text[i];
			}


		}
		return *this;

	}

	Text & Text::operator=(Text && source) //Move
	{
		//std::cout << "MOVE OPERATOR" << std::endl;
		if (this != &source) {
			m_File_Name = source.m_File_Name;
			m_Line_Count = source.m_Line_Count;

			delete[] m_Text;
			

			m_Text = source.m_Text;

			source.m_Text = nullptr;

		}

		return *this;

	}

	void Text::display() const  //made for testing purposes
	{
		for (size_t i = 0U; i < m_Line_Count; ++i) { 
			std::cout << m_Text[i] << std::endl;
		}

	}

	Text::~Text()
	{
			delete[] m_Text;
		
	}


}