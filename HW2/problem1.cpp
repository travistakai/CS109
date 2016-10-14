#include <stdint.h>
#include <cstdio>
#include <limits>
#include <cstdint>
#include <cinttypes>
use std;
class CardReader
{
	private:
		uint8_t studentsPresent = 0;
		bool reserveSeat(uint8_t* seatNum, uint8_t* present)
		{
			// number |= 1 << x; Bitwise OR with 1 at position x
			// number &= ~(1 << x); Bitwise NOT AND to clear bit at position x
			// number ^= 1 << x; Bitwise toggle at position x
			// bit = (number >> x) & 1; Puts value of bit x in variable bit

			// if(checkSeat(*seatNum))
			// {
			// 	*present--;
			// 	return true;
			// }
			// else
				return false;
		};


	public:
		CardReader(){};
		uint8_t seatsFilled()
		{
			return 0;
		};
};

// remember to check if student id is within normal range
// check if student is already checked in to given seat
// 

int main()
{
	int tester = 4;
	int* test = &tester;

	int* array = calloc(32, sizeOf(double));
	*array |= 1 << 220
    std::printf("Decimal:\t%i \n", (*array >> 220)&1);
	free(array);


	return 0;
}