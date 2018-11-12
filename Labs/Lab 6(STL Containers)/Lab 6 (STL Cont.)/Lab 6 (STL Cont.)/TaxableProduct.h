


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