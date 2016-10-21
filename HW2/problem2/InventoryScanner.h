// InventoryScanner function declarations
// Uses stdlib for calloc and cstdio for printf
// Stores each item as a unint8_t since only needs to be 8 bits long

#include <stdlib.h>
#include <cstdio>

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