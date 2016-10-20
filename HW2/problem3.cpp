#include "Heap.h"


int main()
{
	Heap a(20);

	a.insert(15);
	a.insert(13);
	a.insert(12);

	Heap b = a;

	// b + 3;

	// a.insert(9);
	// a.insert(13);
	// a+8;

	int x = a[2];
	printf("%i\n", x);

	return 0;
}