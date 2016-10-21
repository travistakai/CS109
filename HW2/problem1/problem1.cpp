#include "CardReader.h"

	// number |= 1 << x; Bitwise OR with 1 at position x
	// number &= ~(1 << x); Bitwise NOT AND to clear bit at position x
	// number ^= 1 << x; Bitwise toggle at position x
	// bit = (number >> x) & 1; Puts value of bit x in variable bit

CardReader::CardReader()
{
	int studentsPresent = 0;
	reservedArray = (int*)calloc(32, sizeof(char)); //allocate 256 bits to the array of students
	seatedArray = (int*)calloc(32, sizeof(char));
}


CardReader::~CardReader(){};

void CardReader::seatsFilled()
{
	printf("Number of seats occupied out of 256: %i\n", studentsPresent);
}


//checkseat will check the seat of a given student and see if that spot is available to either reserve or occupy
bool CardReader::checkSeat(int studentNumber, int* array)
{
	int taken = (array[(int)floor(studentNumber/32)] >> studentNumber%8) & 1;
	if(taken)
	{
		return true;
	}
	else
		return false;
}

void CardReader::reserveSeat(int studentNumber)
{

	if(studentNumber > 255 || studentNumber < 0)
	{
		printf("Student number is out of range\n");
		return;
	}

	if(checkSeat(studentNumber, reservedArray) == 0)
	{
		studentsPresent++;	//total number of students has increased by 1
		reservedArray[(int)floor(studentNumber/32)] |= 1 << studentNumber%8;	//set seat to be 1 for reserved
		// printf("%i\n", (reservedArray[(int)floor(studentNumber/32)] >> studentNumber%8) & 1);
		printf("Seat has been reserved\n");
	}
	else
		printf("Seat cannot be reserved, someone else has reserved it\n");
};

void CardReader::checkIn(int studentNumber)
{

	if(studentNumber > 255 || studentNumber < 0)
	{
		printf("Student number is out of range\n");
		return;
	}
	else
	{

		if(!checkSeat(studentNumber, seatedArray) && checkSeat(studentNumber, reservedArray))
		{
			seatedArray[(int)floor(studentNumber/32)] |= 1 << studentNumber%8;
			printf("Checked in to seat %i\n", studentNumber);
		}
		else
		{
			printf("Error cannot check into that seat\n");
		}
	}
}

void CardReader::checkOut(int studentNumber)
{
	if(studentNumber > 255 || studentNumber < 0)
	{
		printf("Student number is out of range\n");
		return;
	}

	if(checkSeat(studentNumber, seatedArray) && checkSeat(studentNumber, reservedArray))
	{
		seatedArray[(int)floor(studentNumber/32)] |= 0 << studentNumber%8;
		studentsPresent--;
		printf("Checked out of seat %i\n", studentNumber);
	}
	else
		printf("Error cannot check out of that seat\n");
}

int main()
{	
	CardReader *x = new CardReader();

	x->reserveSeat(12);
	x->reserveSeat(256);
	x->checkIn(12);
	x->checkIn(12);
	x->checkOut(12);
	x->seatsFilled();

	free(x);

	return 0;
}