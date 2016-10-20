// Can have 256 (0-255) products and 256 of each product
// Checkin/out items
// Check if product exists (greater than 0 quantity)
// How many items exist of product
// How many items have stock greater than 0

#include <stdlib.h>
#include <cstdio>
#include <math.h>

class InventoryScanner
{
	private:
		uint8_t* stockArray = (uint8_t*)calloc(256, sizeof(unsigned char)); //holds # of each type of product

		bool productCheck(int productId, int checkType)
		{
			if(checkType == 0) //check if we can insert a product
			{
				if(stockArray[productId] == 255)

					return true; //product is at capacity
				else
					return false; //still room insert a product into stock
			}

			else if(checkType == 1) //check if the product exists (has stock > 0)
			{
				if(stockArray[productId] > 0)
					return true;
				else
					return false;
			}
		}

	public:
		InventoryScanner(){};

		void checkIn(int productId)
		{
			if(productId > 255 || productId < 0)
			{
				printf("Product ID is not within accepted range\n");
				return;
			}

			if(productCheck(productId, 0))
				printf("Cannot insert more of product %i\n", productId);
			else
			{
				printf("Product was inserted successfully\n");
				stockArray[productId]++;
			}
		}

		void checkOut(int productId)
		{
			if(productId > 255 || productId < 0)
			{
				printf("Product ID is not within accepted range\n");
				return;
			}

			if(productCheck(productId, 1))
			{
				stockArray[productId]--;
				printf("Product checked out\n");
			}
			else
				printf("There is no available stock of product %i\n", productId);
		}

		int stockCount(int productId, bool output)
		{
			if(output)
				printf("There are currently %i of product %i in stock\n", stockArray[productId], productId);

			return stockArray[productId];
		}

		void availableProducts()
		{
			int count = 0;
			for (int i = 0; i < 255; ++i)
			{
				count += stockCount(i, false);
			}

			printf("There are currently %i products in stock\n", count);
		}

		// ~InventoryScanner();
};

int main()
{
	InventoryScanner *x = new InventoryScanner();
	x->checkOut(12);
	x->checkIn(12);
	x->stockCount(12, true);
	x->checkOut(12);
	x->stockCount(12, true);
	x->checkIn(12);
	x->stockCount(12, true);
	x->checkIn(12);
	x->stockCount(12, true);
	x->availableProducts();

	return 0;
}