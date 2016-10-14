// lambda expression example
#include "example1_c_plus_plus11_and_14.h"

auto tester = [] (int x) {return x+2;};

int main()
{
	auto y = tester(21); //uses lambda function to add 2
	std::cout<<y;  //returns 23
	return 0;
}