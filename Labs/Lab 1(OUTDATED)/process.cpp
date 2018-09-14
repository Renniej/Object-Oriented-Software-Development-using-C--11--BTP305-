#include "process.h"

std::ostream& process(const char * C_STRING, std::ostream & os)
{

	w1::CString tmp(C_STRING);

	os <<  tmp << endl;
	return os;

}
