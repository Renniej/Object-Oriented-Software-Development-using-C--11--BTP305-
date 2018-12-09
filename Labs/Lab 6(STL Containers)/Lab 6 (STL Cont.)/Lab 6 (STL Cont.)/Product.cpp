
// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 11/11/2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.
#include <iomanip>
#include <string>
#include "Product.h"


using namespace std;

namespace w6 {


	void w6::Product::SetToEmpty()
	{
		m_Prod_ID = "-1";
		m_Price = 0.0;

	}


	bool Product::empty() const
	{
		return (m_Prod_ID == "-1");
	}

	double Product::getPrice() const
	{
		return m_Price;
	}

	void Product::display(std::ostream & os) const
	{
		if (!empty()) {

			os << std::setw(16) << m_Prod_ID;
			os	<< std::setw(16) << m_Price;
			
		}
		else {
			os << "Object In Empty State";
		}
	}

	Product::Product(const char * Prod_ID, double Price)
	{

		m_Prod_ID = Prod_ID;
		m_Price = Price;
	}

	Product::Product()
	{
		SetToEmpty();
	}


	Product::~Product()
	{
	}

}