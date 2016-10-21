// problem1.cpp
// CardReader implementation file
// Uses two seperate arrays to distinguish which seats are reserved vs occupied
// Makes use of a checkSeat function for both reserving and checking into a seat
// Uses bit manipulation in order to minimize space usage of storing student seat info
// 		number |= 1 << x; Bitwise OR with 1 at position x
// 		bit = (number >> x) & 1; Puts value of bit x in variable bit

#include "CardReader.h"

// CardReader default constructor
// Assigns space for 256 seats to be reserved as well as checked into
CardReader::CardReader()
{
	int studentsPresent = 0;
	reservedArray = (int*)calloc(32, sizeof(char)); //allocate 256 bits to the array of students
	seatedArray = (int*)calloc(32, sizeof(char));
}

// CardReader destructor
CardReader::~CardReader(){};

// seatsFilled outputs the number of students present out of 256 seats
void CardReader::seatsFilled()
{
	printf("Number of seats occupied out of 256: %i\n", studentsPresent);
}


// checkSeat will check the seat of a given student and see if that spot is available to either reserve or occupy
// Can be used to reserve as well as checking in by checking specified bit of the array
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
// Used to reserve a student's seat for checking into later
// Checks that seat isnt already reserved
void CardReader::reserveSeat(int studentNumber)
{

	if(studentNumber > 255 || studentNumber < 0)
	{
		printf("Student number is out of range\n");
		return;
	}

	if(checkSeat(studentNumber, reservedArray) == 0) //Seat is not reserved if 0 is returned
	{
		studentsPresent++;
		reservedArray[(int)floor(studentNumber/32)] |= 1 << studentNumber%8;	//set seat to be 1 for reserved
		printf("Seat has been reserved\n");
	}
	else
		printf("Seat cannot be reserved, someone else has reserved it\n");
};

// Used to check into a seat that a student has reserved previously
// Student cannot check into seat without a reservation
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

// Used to checkout of a seat if already checked in
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

	x->reserveSeat(12);		//successful reservation
	x->reserveSeat(256);	//Prints error
	x->checkIn(12);			//Successful checkin
	x->checkIn(12);			//Prints error, already checked in
	x->checkOut(12);		//Successful checkout
	x->seatsFilled();		//Prints # seats filled

	free(x);

	return 0;
}