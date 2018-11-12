#ifndef W6_PRODUCT_H
#define W6_PRODUCT_H

#include <fstream>
#include "iProduct.h"



namespace w6 {

	class Product : public iProduct
	{
		std::string m_Prod_ID; //made a string because we arent doing any data manipulations on it
		double m_Price;



		
		
	public:

		void SetToEmpty();

		bool empty() const;

		double getPrice() const;

		void display(std::ostream& os) const;
		
		Product(const char* Prod_ID, double Price);
		Product();
		~Product();
	};


}



#endif