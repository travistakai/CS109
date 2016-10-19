#include <cstdio>
#include <stdlib.h>
#include <math.h>

class CardReader
{
	// number |= 1 << x; Bitwise OR with 1 at position x
	// number &= ~(1 << x); Bitwise NOT AND to clear bit at position x
	// number ^= 1 << x; Bitwise toggle at position x
	// bit = (number >> x) & 1; Puts value of bit x in variable bit

	private:
		int studentsPresent = 0;
		int* reservedArray = (int*)calloc(32, sizeof(char)); //allocate 256 bits to the array of students
		int* seatedArray = (int*)calloc(32, sizeof(char));

		uint8_t x;

	public:
		CardReader(){};

		void seatsFilled()
		{
			printf("Number of seats occupied out of 256: %i\n", studentsPresent);;
		};

		bool checkSeat(int studentNumber, int* array)
		{
			int taken = (array[(int)floor(studentNumber/32)] >> studentNumber%8) & 1;
			if(taken)
			{
				printf("%s\n", taken);
				return true;
			}
			else
				return false;
		}

		bool reserveSeat(int studentNumber)
		{
			if(studentNumber > 255 || studentNumber < 0)
			{
				printf("Student number is out of range\n");
				return false;
			}

			if(checkSeat(studentNumber, reservedArray) == 0)
			{
				studentsPresent++;	//total number of students has increased by 1
				reservedArray[(int)floor(studentNumber/32)] |= 1 << studentNumber%31;	//set seat to be 1 for reserved
				printf("Seat has been reserved\n");
				return true;
			}
			else
				printf("Seat cannot be reserved, someone else has reserved it\n");
				return false;
		};

		void checkIn(int studentNumber)
		{
			if(studentNumber > 255 || studentNumber < 0)
			{
				printf("Student number is out of range\n");
				return;
			}

			if(!checkSeat(studentNumber, seatedArray) && checkSeat(studentNumber, reservedArray))
			{
				seatedArray[(int)floor(studentNumber/32)] |= 1 << studentNumber%31;
				printf("Checked in to seat %i\n", studentNumber);
			}
			else
				printf("Error cannot check into that seat\n");
		}

		void checkOut(int studentNumber)
		{
			if(studentNumber > 255 || studentNumber < 0)
			{
				printf("Student number is out of range\n");
				return;
			}

			if(checkSeat(studentNumber, seatedArray) && checkSeat(studentNumber, reservedArray))
			{
				seatedArray[(int)floor(studentNumber/32)] |= 0 << studentNumber%31;
				printf("Checked out of seat %i\n", studentNumber);
			}
			else
				printf("Error cannot check out of that seat\n");
		}
};

// remember to check if student id is within normal range - done
// check if student is already checked in to given seat

int main()
{	
	CardReader *x = new CardReader();

	x->reserveSeat(12);
	x->reserveSeat(256);
	x->checkIn(12);
	x->checkIn(12);
	x->checkOut(12);
	x->seatsFilled();
	
	// *array |= 1 << 31;
 //    printf("Decimal:\t%i \n", (*array >> 31) & 1);
	// free(array);


	return 0;
}