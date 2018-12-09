// iProduct.h
// ProdUtil.h
// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 11/11/2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.
#ifndef W6_IPRODUCT_H
#define W6_IPRODUCT_H
#include <fstream>

namespace w6
{
	class iProduct
	{
	public:
		virtual double getPrice() const = 0;
		virtual void display(std::ostream&) const = 0;
	};
}
#endif

