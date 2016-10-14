// variable template example
#include "example1_c_plus_plus11_and_14.h"

template<typename T> T x = T(12.314); //template that contains initial value of 12.314

int main()
{
	std::cout<<"Int version:\n"<<x<int>;
	std::cout<<"\nDouble version:\n"<<x<double>;
	std::cout<<"\nFloat version:\n"<<x<float>;
	std::cout<<"\nBoolean version:\n"<<x<bool>;
	return 0;
}