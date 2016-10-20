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

GPP = g++ -std=c++14
GPPFLAGS = -O3 -ansi -Wall
DEBUGFLAGS = -g -ansi -Wall
INCLUDE = -I./problem1
SUBDIRS = problem1 problem2 problem3

all: problem1 problem2 problem3

#Link command:
problem1: problem1/problem1.o
	$(GPP) $(GPPFLAGS) $(INCLUDE) problem1/problem1.o -o problem1

problem2: problem2/problem2.o
	$(GPP) $(GPPFLAGS) $(INCLUDE) problem2/problem2.o -o problem2

problem3: problem3/problem3.o
	$(GPP) $(GPPFLAGS) $(INCLUDE) problem3/problem3.o -o problem3

#Compilation commands:
problem1.o: problem1/problem1.cpp
	$(GPP) $(GPPFLAGS) $(INCLUDE) -c problem1.cpp -o problem1.o

problem2.o: problem2/problem2.cpp
	$(GPP) $(GPPFLAGS) $(INCLUDE) -c problem2.cpp -o problem2.o

problem3.o: problem3/problem3.cpp
	$(GPP) $(GPPFLAGS) $(INCLUDE) -c problem3.cpp -o problem3.o

#make clean
clean:
	rm -f *.exe
	rm -f problem1/*.o
	rm -f problem2/*.o
	rm -f problem3/*.o

%.o: %.cc
	g++ -c $< -o $@