// Generic lambda example
#include "example1_c_plus_plus11_and_14.h"

auto tester = [] (auto x) {return x+2;}; //takes auto as a variable type

int main()
{
	auto x = tester(12); //x becomes an int
	return 0;
}