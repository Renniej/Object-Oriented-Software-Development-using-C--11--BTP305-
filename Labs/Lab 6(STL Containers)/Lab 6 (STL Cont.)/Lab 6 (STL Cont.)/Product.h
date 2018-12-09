// ProdUtil.h
// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 11/11/2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.
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