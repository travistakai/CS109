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
	MaxSize = myHeap.MaxSize;
	array = (int *) calloc(MaxSize,sizeof(int));
	for (int i = 1; i < MaxSize; ++i)
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

// Works
Heap Heap::operator+(Heap a)
{
	Heap passed(MaxSize + a.MaxSize);

	int max = (MaxSize > a.MaxSize ? MaxSize : a.MaxSize);

	for (int i = 0; i < max; ++i)
	{
		if(i < MaxSize && array[i] != 0)
		{
			passed.insert(array[i]);
		}

		if(i < a.MaxSize && a.array[i] != 0)
		{
			passed.insert(a.array[i]);
		}
	}
	return passed;
}

// Works
Heap Heap::operator+(int a)
{
	Heap passed = *this;
	passed.insert(a);
	return passed;
}

// Works
int Heap::operator[](int num)
{
	return this->array[num];
}

// Works
void Heap::operator=(Heap &myHeap)
{
	Heap passed = myHeap;
	*this = passed;
}

// Works
void Heap::operator+=(int a)
{
	insert(a);
}

Heap Heap::operator+=(Heap const &myHeap)
{
	Heap copy = *this + myHeap;
	std::cout << "Copy " << copy + myHeap << std::endl;
	std::cout << "Copy " << copy + myHeap << std::endl;
	return copy + myHeap;
	// std::cout << "Copy" << *this << std::endl;
}


// Needs work
std::ostream& operator<< (std::ostream& out, const Heap& heap) {
    for (int i = 0; i < heap.Nel+1; ++i)
    {
        out << heap.array[i] << " ";
    }
   return out;
}

int main()
{
	Heap a(20);

	a.insert(13);
	a.insert(15);
	a.insert(12);

	Heap b(20);
	b.insert(21);

	
	// Heap c = a;
	a += 16;
	a += b;
	std::cout << a;


	// b + 12;
	// b + 21;
	// Heap c = b + a;
	// b.insert(20);

	// b + 3;

	// a.insert(19);
	// a.insert(13);
	// a+8;

	// int x = c[1];
	// printf("%i\n", x);

	return 0;
}