﻿// Workshop 6 - STL Containers
// w6.cpp
// Updated by cornel on 27.09.2018

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "iProduct.h"
#include "ProdUtil.h"

using namespace w6;

int main(int argc, char** argv) {

	std::cout << "Command Line: ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;
	if (argc != 2) {
		std::cerr << "\n***Incorrect number of arguments***\n";
		return 1;
	}
	std::ifstream productList(argv[1]);
	if (!productList) {
		std::cerr << "\n***Failed to open file " << argv[1] << "***\n";
		return 2;
	}
	std::cout << std::fixed << std::setprecision(2);

	// TODO: Define a variable ot type vector named "products"
	std::vector<iProduct*> products;

	std::cout << "====================================\n";
	std::cout << "Reading data from the file\n";
	std::cout << "====================================\n";
	{
		// TODO: Read from the file one record at a time and create a product.
		// - Print a message before starting processing a product.
		// - Add the product to the vector "products", created above.
		// - Handle any thrown exceptions and print the message.

		int Record_Count = 1;

		do  {

			std::cout << "Processing record " << Record_Count << ": ";

			try {
				

				iProduct * tmp = readProduct(productList);

				if (tmp == nullptr) {
					std::cout << "no such record! Reached the end of the file!" << std::endl;
				}
				else {
					
					products.push_back(tmp);
					std::cout << "done!" << std::endl;
				}
				
			}
			catch (const char* msg) {
				std::cout << msg << std::endl;
			}

			Record_Count++;
		} while (productList.good());

	}

	std::cout << "====================================\n";

	std::cout << std::endl;
	std::cout << "====================================\n";
	std::cout << "Printing the content of the vector\n";
	std::cout << "====================================\n";

	double total = 0.0;
	std::cout << "      Product No         Taxable\n";
	std::cout << "------------------------------------\n";
	for (auto i = 0u; i < products.size(); i++) {
		total += products[i]->getPrice();
		std::cout << *products[i];
	}
	std::cout << "------------------------------------\n";
	std::cout << std::setw(22) << "Total: ";
	std::cout << std::setw(10) << total << std::endl;
	std::cout << "====================================\n";


	return 0;
}