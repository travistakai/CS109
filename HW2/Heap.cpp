class Heap
{
	private:
		int * array;
		int MaxSize, Nel;
		void adjust (int a[], int i, int n);
	public:
		Heap(int MSize);
		bool insert (int item);
		bool delMax(int & item);
		~Heap();
};