#include <cstdio>
#include <stdlib.h>
#include <math.h>

class CardReader
{
	private:
		int studentsPresent;
		int* reservedArray;
		int* seatedArray;
	public:
		CardReader();
		~CardReader();
		void seatsFilled();
		bool checkSeat(int studentNumber, int* array);
		void reserveSeat(int studentNumber);
		void checkIn(int studentNumber);
		void checkOut(int studentNumber);
};