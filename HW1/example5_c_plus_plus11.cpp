// forward_list example
#include "example1_c_plus_plus11_and_14.h"
#include <forward_list>

int main()
{
	std::forward_list<int> words1 {1, 2, 3, 4, 5}; //list of ints that cannot be accessed except from front
	std::cout<< words1.front() << '\n'; //returns 1 from the front of the list
	return 0;
}