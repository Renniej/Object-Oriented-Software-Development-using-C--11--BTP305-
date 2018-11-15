#ifndef W7_DATATABLE_H
#define W7_DATATABLE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>

namespace w7 {
	
	class DataTable {

		
		std::vector<double> m_x; //Indepedent value
		std::vector<double> m_y; //Dependent value

		size_t m_fwidth; //field width for display
		size_t m_dec; //number of decimals to display

	public:


		double mean() const {
		
			return std::accumulate(m_y.begin(), m_y.end(), double(0)) / m_y.size();
	
		};


		double sigma() const {



		};

		DataTable(std::ifstream& ifs, size_t fwidth, size_t dec) { //Made under the assumption file contains same format at all times
		
			if (ifs.good()) {



				do { //Continue reading data from file till end of file is reached or there is an error;

					std::string line;

					std::getline(ifs, line);

					if (!line.empty()) { //if line grabbed from file isn't epmpty then store data
						std::cout << "Line grabbed: " << line << std::endl;

						m_x.push_back(std::stod(line.substr(0, line.find(" "))));
						m_y.push_back(std::stod(line.substr(line.find(" ") + 1, line.back())));

						std::cout << "Values stored in DataTable: " << m_x.back() << " " << m_y.back() << std::endl << std::endl;
					}
					else { //else if a empty line is detected then continue onto next loop cycle
						std::cout << "Empty Line Detected" << std::endl;
						continue;
					}

				} while (ifs.good());

				//should probably do error checking for width and decimals length
				m_fwidth = fwidth;
				m_dec = dec;

				//std::cout << "m_fwidth & m_dec: " << m_fwidth << " " << m_dec << std::endl;



			}
		
		};


		~DataTable() {};


	};

}

#endif