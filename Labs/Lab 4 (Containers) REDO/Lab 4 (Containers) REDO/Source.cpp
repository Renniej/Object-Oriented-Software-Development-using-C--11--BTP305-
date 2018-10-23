#include "Message.h"


using namespace w4;

const char REC_DELIMITER = '\n';

int main(void) {

	std::ifstream tweets("tweets.dat");

	Message w4(tweets, REC_DELIMITER);
	Message w5(tweets, REC_DELIMITER);
	Message w6(tweets, REC_DELIMITER);


	w4.display(std::cout);
	w5.display(std::cout);
	w6.display(std::cout);

}