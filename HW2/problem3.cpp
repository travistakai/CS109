#include "Heap.h"


int main()
{
	Heap a(20);

	a.insert(13);
	a.insert(15);
	a.insert(12);

	Heap b = a;
	// b + 12;
	// b + 21;
	// Heap c = b + a;
	// b.insert(20);

	// b + 3;

	// a.insert(19);
	// a.insert(13);
	// a+8;

	int x = b[2];
	printf("%i\n", x);

	return 0;
}