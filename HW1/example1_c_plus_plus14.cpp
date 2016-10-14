// decltype(auto) example
#include "example1_c_plus_plus11_and_14.h"


decltype(auto) func()
{
	static int test = 3;

	auto& compare(test);
	return compare;
}


int main()
{
	int i = 1;
	decltype(auto) test1 = i; //test1 is an int
	decltype(auto) y = func();//y is an int&

	static_assert(std::is_same<decltype(y), int&>(), "false");

	return 0;
}