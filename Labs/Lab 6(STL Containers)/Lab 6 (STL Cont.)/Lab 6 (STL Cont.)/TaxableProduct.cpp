
// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 11/11/2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.
#include "TaxableProduct.h"




namespace w6 {

	const double TaxableProduct::HST = 0.13;
	const double TaxableProduct::PST = 0.8;

	TaxableProduct::TaxableProduct(const char * Prod_ID, double Price, const char * Tax_Code) : Product(Prod_ID, Price)
	{
		m_Tax_Code = Tax_Code;
	}

	void TaxableProduct::display(std::ostream & os) const
	{

		Product::display(os);
		if ( !Product::empty() ) {
			os << " " << (m_Tax_Code == "H" ? "HST" : "PST");
		}
	}

	double TaxableProduct::getPrice() const
	{
		return (m_Tax_Code == "H" ? Product::getPrice() * 1.13 : Product::getPrice()*1.08);
	}

	TaxableProduct::TaxableProduct()
	{
		Product::SetToEmpty();
		m_Tax_Code = "N/A";
	}


	TaxableProduct::~TaxableProduct()
	{
	}
}