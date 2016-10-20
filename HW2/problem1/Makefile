# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#	Makefile for Unix & Linux Systems	#
#	using a GNU C++ compiler	#
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

# compiler flags
#	-g	--Enable debugging
#	-Wall	--Turn on all warnings
#	-D_USE_FIXED_PROTOTYPES_
#	--Force the compiler to use the correct headers
#	-ansi	--Don't use GNU ext; do use ansi standard.

CXX = g++
CXXFLAGS = -O3 -ansi -Wall
DEBUGFLAGS = -g -ansi -Wall
INCLUDE = -I./problem1

#Link command:
Problem1: problem1.o
	$(CXX) $(CXXFLAGS) $(INCLUDE) problem1.o -o Problem1

#Compilation commands:
problem1.o: problem1.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c problem1.cpp -o problem1.o

#make clean
clean:
	rm	-f	*.o
