#include <fstream>
#include <vector>
#include<string>
#include "Item.h"
#include "Utilities.h"


int main() {

	std::vector<Item> Items;

	std::ifstream file("Inventory2.dat");



	while (file.good()) {

		std::string line;
		std::getline(file, line);

		std::cout << "Line grabbed from file : " << line << std::endl << std::endl;


		try {
			Item test(line);
			Items.push_back(test);
		}
		catch (std::string msg) {
			std::cout << "ERROR : " << msg << std::endl;
		}
	}



}
