// tuple example
#include "example1_c_plus_plus11_and_14.h"
#include <tuple>

auto example = std::make_tuple(2.9, 4, 'z'); //tuple containing a double, int, and char 


int main()
{
	double a = std::get<0>(example); //accessing of the first element
	int b = std::get<1>(example);	//accessing of second element
	char c = std::get<2>(example);	//accessing of third element

	std::cout<<a<<'\n'<<b<<'\n'<<c;

	return 0;
}