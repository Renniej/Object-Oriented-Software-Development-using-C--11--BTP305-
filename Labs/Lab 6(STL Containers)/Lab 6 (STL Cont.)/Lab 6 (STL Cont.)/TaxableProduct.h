// ProdUtil.h
// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 11/11/2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.


#include "Product.h"
#ifndef W6_TAXABLEPRODUCT_H
#define W6_TAXABLEPRODUCT_H


namespace w6 {


	class TaxableProduct : public Product
	{
		static double const PST;
		static double const HST;
		std::string m_Tax_Code;

	public:
		
		TaxableProduct(const char* Prod_ID, double Price, const char* Tax_Code);
		void display(std::ostream& os) const;
		double getPrice() const;
		TaxableProduct();
		~TaxableProduct();
	};

}

#endif