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

CXX = g++ -std=c++14
CXXFLAGS = -O3 -ansi -Wall
DEBUGFLAGS = -g -ansi -Wall
INCLUDE = -I./problem1
SUBDIRS = problem1 problem2 problem3

#Link command:
Problem1: problem1/problem1.o
	$(CXX) $(CXXFLAGS) $(INCLUDE) problem1/problem1.o -o Problem1

Problem2: problem2/problem2.o
	$(CXX) $(CXXFLAGS) $(INCLUDE) problem2/problem2.o -o Problem2

Problem3: problem3/problem3.o
	$(CXX) $(CXXFLAGS) $(INCLUDE) problem3/problem3.o -o Problem3

#Compilation commands:
problem1.o: problem1/problem1.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c problem1.cpp -o problem1.o

problem2.o: problem2/problem2.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c problem2.cpp -o problem2.o

problem3.o: problem3/problem3.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c problem3.cpp -o problem3.o

#make clean
clean:
	rm -f *.exe
	rm problem1/ -f *.o
	rm problem2/ -f *.o
	rm problem3/ -f *.o

%.o: %.cc
	g++ -c $< -o $@