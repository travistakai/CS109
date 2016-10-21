# Makefile for HW2
# Will compile all files from subdirectories and store output in current dir

GPP = g++ -std=c++14
GPPFLAGS = -O3 -ansi -Wall

all: problem1 problem2 problem3

#Link command:
problem1: problem1/problem1.o
	$(GPP) $(GPPFLAGS) problem1/problem1.o -o problem1

problem2: problem2/problem2.o
	$(GPP) $(GPPFLAGS) problem2/problem2.o -o problem2

problem3: problem3/problem3.o
	$(GPP) $(GPPFLAGS) problem3/problem3.o -o problem3

#Compilation commands:
problem1.o: problem1/problem1.cpp
	$(GPP) $(GPPFLAGS) -c problem1.cpp -o problem1.o

problem2.o: problem2/problem2.cpp
	$(GPP) $(GPPFLAGS) -c problem2.cpp -o problem2.o

problem3.o: problem3/problem3.cpp
	$(GPP) $(GPPFLAGS) -c problem3.cpp -o problem3.o

#make clean for all main and subdirectories
clean:
	rm -f *.exe
	rm -f problem1/*.o
	rm -f problem2/*.o
	rm -f problem3/*.o

%.o: %.cc
	g++ -c $< -o $@