#include "Heap.h"

void Heap::adjust (int a[], int i, int n)
{
	int j = 2*i, item = a[i];
	while ( j <= n )
	{
		if (j<n && (a[j] < a[j+1]))
			j++;
			// Compare left and right child
			// and let j be the larger child
		if (item >= a[j]) 
			break;
		
		a[j/2] = a[j]; j*=2;
	}
		
	a[j/2] = item;
}

Heap::Heap(int MSize):MaxSize(MSize)
{
	array = (int *) calloc(MSize+1,sizeof(int));
	Nel = 0;
}

// Copy constructor of the Heap class
// Takes in a pre-existing Heap object as a parameter and returns a Heap with the same data (aka a copy of the object)
Heap::Heap(const Heap &myHeap)
{
	int size = myHeap.MaxSize;
	// printf("%i\n", size);
	Heap passed(size);
	passed.array = (int *) calloc(size+1,sizeof(int));
	passed.Nel = myHeap.Nel;
	for (int i = 1; i < size; ++i)
	{
		if(myHeap.array[i] != 0)
		{
			insert(myHeap.array[i]);
		}
	}
}

Heap::~Heap(){}

bool Heap::insert (int item)
{
	int i = ++Nel;
	if ( i == MaxSize)
	{
		std::cout << "heap size exceeded" << std::endl;
		return false;
	}
	
	while ( (i > 1 ) && ( array[i/2] < item ))
	{
		array[i] = array[i/2];
		i/=2;
	}
	array[i] = item;
}

bool Heap::delMax(int & item)
{
	if ( !Nel) { std::cout << "heap is empty" << std::endl ; return false; }
		item = array[1];
		array [1] = array[Nel--];
		adjust (array,1,Nel);
		return true;
}

Heap Heap::operator+(Heap a)
{
	int size = (sizeof(this->array)+sizeof(a.array))/4;
	Heap passed(size);

	for (int i = 0; i < sizeof(this->array)/4; ++i)
	{
		if(this->array[i] != 0)
			passed.insert(this->array[i]);
	}

	for (int i = 0; i < sizeof(a.array)/4; ++i)
	{	if(a.array[i] != 0)
			passed.insert(a.array[i]);
	}
	return passed;
}

// Works
Heap Heap::operator+(int a)
{
	this->insert(a);
	return *this;
}

// Works
int Heap::operator[](int num)
{
	return this->array[num];
}

// Needs to copy, not just point
Heap Heap::operator=(Heap &myHeap)
{
	Heap passed = myHeap;
	return passed;
}

// Needs work
Heap Heap::operator+=(auto a)
{
	return *this+a;
}

// Needs work
void Heap::operator<<(Heap a)
{
	for (int i = 0; i < sizeof(this->array)/4; ++i)
	{
		std::cout << this->array[i];
	}
}