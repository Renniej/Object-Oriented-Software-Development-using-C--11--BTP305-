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