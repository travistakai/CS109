#include <stdlib.h>
#include <cstdio>
#include <math.h>

class InventoryScanner
{
	private:
		uint8_t* stockArray;
		bool productCheck(int productId, int checkType);
	public:
		InventoryScanner();
		~InventoryScanner();
		void checkIn(int productId);
		void checkOut(int productId);
		int stockCount(int productId, bool output);
		void availableProducts();
};