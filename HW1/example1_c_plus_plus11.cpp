// Trailing return type example
#include "example1_c_plus_plus11_and_14.h"

template<class T, class U>

auto multiply (T a, U b)->decltype(a*b) //trailing return type since both a and b have yet to be initialized
{
	return a*b;
}

int main()
{
	auto test = multiply(4.3, 2);
	
	return 0;
}