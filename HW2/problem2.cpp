// Can have 256 (0-255) products and 256 of each product
// Checkin/out items
// Check if product exists (greater than 0 quantity)
// How many items exist of product
// How many items have stock greater than 0

#include <stdlib.h>
#include <cstdio>
#include <math.h>

// number |= 1 << x; Bitwise OR with 1 at position x
// number &= ~(1 << x); Bitwise NOT AND to clear bit at position x
// number ^= 1 << x; Bitwise toggle at position x
// bit = (number >> x) & 1; Puts value of bit x in variable bit

class InventoryScanner
{
	private:
		int* productArray = (int*)calloc(32, sizeof(char)); //holds if product is present or not (using 0 or 1)
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
				int productPresent = (productArray[(int)floor(productId/32)] >> productId%8) & 1;
				if(productPresent)
					return true;
				else
					return false;
			}
		}

	public:
		InventoryScanner();

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
				stockArray[productId] += 1;
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
				stockArray[productId] -= 1;
				printf("Product checked out\n");
			}
			else
				printf("There is no available stock of product %i\n", productId);
		}

		void stockCount(int productId)
		{
			printf("There are currently %i of product %i in stock\n", stockArray[productId], productId);
		}

		void availableProducts()
		{
			int count = 0;
			for (int i = -1; i < 255; ++i)
			{
				count += productCheck(i, 1);
			}

			printf("There are currently %i products in stock\n", count);
		}

		~InventoryScanner();
};

int main()
{

}