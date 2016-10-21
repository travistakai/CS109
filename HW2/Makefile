# Makefile for HW2
# Will compile all files from subdirectories and store output in current dir

GPP = g++ -std=c++14
GPPFLAGS = -O3 -ansi -Wall

all: p1 p2 p3

#Link command:
p1: problem1/problem1.o
	$(GPP) $(GPPFLAGS) problem1/problem1.o -o p1

p2: problem2/problem2.o
	$(GPP) $(GPPFLAGS) problem2/problem2.o -o p2

p3: problem3/problem3.o
	$(GPP) $(GPPFLAGS) problem3/problem3.o -o p3

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
	rm -f p1
	rm -f p2
	rm -f p3

%.o: %.cc
	g++ -c $< -o $@