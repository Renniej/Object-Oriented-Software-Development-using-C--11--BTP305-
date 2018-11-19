#ifndef W7_DATATABLE_H
#define W7_DATATABLE_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <iterator>


namespace w7 {
	




	template<class T>
	class DataTable {

		
		std::vector<T> m_x; //Indepedent value
		std::vector<T> m_y; //Dependent value

		size_t m_fwidth; //field width for display
		size_t m_dec; //number of decimals to display

	public:

		void display(std::ostream& os) const {

			os << std::setw(m_fwidth) << "X" << std::setw(m_fwidth) << "Y" <<std::endl; // set field widths


			for (size_t i = 0U; i < getSize(); ++i) {

				os << std::fixed << std::setprecision(m_dec) << std::setw(m_fwidth) << m_x[i] << std::setw(m_fwidth) << m_y[i] << std::endl;

			}

		};

		friend std::ostream& operator<<(std::ostream& os, const DataTable& src) {  //check why this needs to be friend later.... 

			src.display(os);
			return os;

		};


		T mean() const { //returns mean of y  values
		
			return std::accumulate(m_y.begin(), m_y.end(), T(0)) / getSize();
	
		};


		T sigma() const { //performs standard deviation forumla for y values

			return sqrt(std::accumulate(m_y.begin(), m_y.end(), T(0), [&](T x, T y) {
				
				// X = Current value of INIT
				//Y =  Currently grabbed value from m_y Vector

				//std::cout << "X: " << x << " Y: " << y << std::endl;  
				return x + pow(y-mean(),2); 
			
			
			}) / (getSize() - 1));

		};

		T median() const {
		
			std::vector<T> tmp; //create tmp container to hold copy of m_y array
			std::copy(m_y.begin(), m_y.end(), std::back_inserter(tmp)); //copy values over to tmp. Since tmp is empty we have to use back inserter instead of tmp.begin()
			std::sort(tmp.begin(), tmp.end()); //sort tmp container from least to greatest
			

			return tmp.size() % 2 == 0 ? tmp[ceil(tmp.size() / 2.0)] : tmp[tmp.size()/2] + tmp[(tmp.size()/2)+1];
		

		};

		size_t getSize() const {
			return m_y.size();
		};

		void regression(T& slope, T& y_intercept) const { //y=mx + B
		
			T mean_x = std::accumulate(m_x.begin(), m_x.end(), T(0)) / getSize(); //mean of x
			T mean_X_t_Y = std::inner_product(m_y.begin(), m_y.end(), m_x.begin(), T(0)) / getSize();
			T mean_Xsq = std::accumulate(m_x.begin(), m_x.end(), T(0), [](T x, T y) { return x + std::pow(y, 2); }) / getSize(); //mean of x^2

			slope = (mean_x * mean() - mean_X_t_Y) / ( std::pow(mean_x,2) - mean_Xsq ) ;
			y_intercept = mean() - slope * mean_x;

		};

		DataTable(std::ifstream& ifs, size_t fwidth, size_t dec) { //Made under the assumption file contains same format at all times
		
			if (ifs.good()) {



				do { //Continue reading data from file till end of file is reached or there is an error;

					std::string line;

					std::getline(ifs, line);

					if (!line.empty()) { //if line grabbed from file isn't epmpty then store data
						//std::cout << "Line grabbed: " << line << std::endl;

						m_x.push_back(std::stod(line.substr(0, line.find(" "))));
						m_y.push_back(std::stod(line.substr(line.find(" ") + 1, line.back())));

						//std::cout << "Values stored in DataTable: " << m_x.back() << " " << m_y.back() << std::endl << std::endl;
					}
					else { //else if a empty line is detected then continue onto next loop cycle
						//std::cout << "Empty Line Detected" << std::endl << std::endl;
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