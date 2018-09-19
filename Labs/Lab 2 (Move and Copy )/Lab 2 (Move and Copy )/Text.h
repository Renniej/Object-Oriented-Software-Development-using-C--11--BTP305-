// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 9/19/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <string>
#include <fstream>

using namespace std;


namespace w2 {
	class Text
	{

		string m_File_Name;
		string * m_Text;
		size_t m_Line_Count;

		void SetToEmpty();

	public:

		size_t size() const;

		Text();
		Text(const string& name);
		Text(const Text& source);
		Text(Text&& source);

		Text& operator=(const Text& source);
		Text& operator=(Text&& source);
		

		void display() const; //made for testing purposes



		~Text();
	};

}