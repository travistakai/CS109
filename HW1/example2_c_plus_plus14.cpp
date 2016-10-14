// Return type deduction example
#include "example1_c_plus_plus11_and_14.h"

auto area(int x, double y)
{
	return x*y; //will return a double
}

int main()
{
	auto a = area(7, 21.5); //a is a automatically deduced to be double based on input
	std::cout<<a;
	return 0;
}