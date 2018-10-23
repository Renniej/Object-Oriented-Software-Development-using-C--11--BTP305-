#include "Notifications.h"


using namespace w4;

const char REC_DELIMITER = '\n';

int main(void) {

	std::ifstream tweets("tweets.dat");

	Message w4(tweets, REC_DELIMITER);
	Message w5(tweets, REC_DELIMITER);
	Message w6(tweets, REC_DELIMITER);
	Message w7(tweets, REC_DELIMITER);
	Message w8(tweets, REC_DELIMITER);




	Notifications testNot;


	testNot += w4;
	testNot += w5;
	testNot += w6;
	testNot += w7;
	testNot += w8;



	Notifications testNot2(std::move(testNot));
	


	testNot2.display(std::cout);

}