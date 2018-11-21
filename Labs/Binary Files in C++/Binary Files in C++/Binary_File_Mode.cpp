#include <iostream>
#include <fstream>
#include <string>
#include <cstring>


int main() {

		char input[100];
		strcpy(input, "Tai-Juan is somewhat amazing!");

		std::fstream file("anil.bin", std::ios::binary | std::ios::in | std::ios::out | std::ios::trunc); //Binary mode,  in/out = read/write,  trunc = make file if it doesn't exist/add to file

		if (file.good()) {

			//write to file
			for (int i = 0; i <= strlen(input); ++i) {

				file.put(input[i]);

			}


			file.seekg(0); //reset file line indicator so it reads from the begining of the file.
		}
		else {

			std::cout << "FILE FAILED TO OPEN" << std::endl;

		}
	
		char ch;

		while (file.good()) {

			file.get(ch);
			std::cout << ch << std::endl;

		}



	return 0;
}