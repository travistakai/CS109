#include <stdlib.h>
#include <stdio.h>
#include <iostream>
class Heap
{
	private:
		int * array;
		int MaxSize, Nel;
		void adjust (int a[], int i, int n);
	public:
		Heap(int MSize);
		Heap(Heap &myHeap);
		bool insert (int item);
		bool delMax(int & item);
		Heap operator+(Heap a);
		Heap operator+(int a);
		int operator[](int a);
		Heap operator=(Heap &myHeap);
		~Heap();
};