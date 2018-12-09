
// Name: Tai-Juan Rennie
// Seneca Student ID: 101359172
// Seneca email: trennie1@myseneca.ca
// Date of completion: 11/11/2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.
#include <string>
#include <iostream>
#include "ProdUtil.h"
#include "TaxableProduct.h"

namespace w6 {



	std::ostream & operator<<(std::ostream & os, const iProduct & prod) //display Product information
	{
		prod.display(os);
		os << std::endl;
		return os;
	}

	iProduct * readProduct(std::ifstream & ifs) //Create product from line in file
	{
		
		iProduct * tmp = nullptr;

		if (ifs.good()) {

			std::string line;
			int Spaces = 0;

			std::getline(ifs, line, '\n'); //Grab line from file

			//Count number of spaces in line to determine if 
			//iproduct object is taxable or not.

			if (!line.empty()) {
				for (size_t i = 0U; i < line.size(); ++i) {

					if (line.at(i) == ' ') { 
						//.-. professor made the sales.dat profile purposefuly flawed so I have to check for
						//multiple spaces
						//Probs a better way to do this but... na
						if (!(line.at(i + 1) == ' ')) {
							++Spaces;
						}


					}
				}

				if (Spaces == 1) { //If only 1 space exist in line then the info is meant for a normal product
					tmp = new Product(line.substr(0, line.find(" ")).c_str(), std::stod(line.substr(line.find(" "), line.back())));
					//tmp->display(std::cout);
				}
				else if (Spaces == 2) {

					std::string Tax_Code(line.substr(line.find_last_of(" ") + 1, line.back()));  //Grab taxcode from line

					if (Tax_Code == "H" || Tax_Code == "P") { //Check if taxcode is valid 
						tmp = new TaxableProduct(line.substr(0, line.find(" ")).c_str(), std::stod(line.substr(line.find(" "), line.back())), Tax_Code.c_str());
						//tmp->display(std::cout);
					}
					else { //else throw error message
						throw "Unrecognizable Tax Code!";
					}

				}
			}
			

		}
		//std::cout << "Numer Of Spaces: " << Spaces << std::endl;

		return tmp;
	}





}