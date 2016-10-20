#include <iostream>
#include <string>

int main()
{
  int* array = (int*)calloc(32, sizeof(double));
  std::cout << sizeof(array) << std::endl;
  array[31] = 3;
  std::cout << array[31] << std::endl;
}