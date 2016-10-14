// array example
#include "example1_c_plus_plus11_and_14.h"

int main()
{

	std::array<int, 3> a1{ {1, 2, 3} }; //an array full of 3 ints
	

	for(const auto& s: a1)
        std::cout << s << '\n'; //prints out the 3 ints in orders

	return 0;
}