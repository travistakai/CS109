// auto specifier example
#include "example1_c_plus_plus11_and_14.h"
#include <typeinfo>

auto x = 4.5; //double
auto y = x + 12;//double + int

int main()
{
	std::cout << typeid(decltype(x)).name()<<'\n'; //returns double
	return 0;
}