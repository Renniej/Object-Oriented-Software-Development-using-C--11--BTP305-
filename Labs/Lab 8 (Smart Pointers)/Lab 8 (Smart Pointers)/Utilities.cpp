#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"
// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 11/22/2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

using namespace std;

namespace w8
{
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price)
	{
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers

		for (size_t i = 0U; i < desc.size(); ++i) {

			for (size_t j = 0U; j < price.size(); ++j) {


				if (desc[i].code == price[j].code) {

					Product* tmp = new Product(desc[i].desc, price[j].price);
					tmp->validate();
					priceList += tmp;
					delete tmp;
				}


			}



		}


		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price)
	{
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		for (size_t i = 0U; i < desc.size(); ++i) {

			for (size_t j = 0U; j < price.size(); ++j) {


				if (desc[i].code == price[j].code) {

					std::unique_ptr<Product> tmp = make_unique<Product>(desc[i].desc, price[j].price);
					tmp->validate();
					priceList += std::move(tmp); //transfer ownership to function overload
				}


			}



		}

		return priceList;
	}
}