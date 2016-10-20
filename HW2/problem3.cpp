#include "Heap.h"


int main()
{
	Heap *a = new Heap(1);
	a++;
	free(a);
	return 0;
}