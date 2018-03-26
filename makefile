#EDGAR ARAKELYAN
#BACARRAT SIMULATION MAKEFILE

OBJS = Shoe.o Statistics.o User.o bacarratSimulator.o
CC = g++ -Wall -pedantic -std=c++11 -g
DEPS = Shoe.h Statistics.h User.h
DEPS1 = Shoe.h
DEPS2 = Statistics.h
DEPS3 = User.h

all: bacarratSimulator

Shoe.o: Shoe.cpp $(DEPS1)
		$(CC) -c Shoe.cpp

Statistics.o: Statistics.cpp $(DEPS2)
		$(CC) -c Statistics.cpp

User.o: User.cpp $(DEPS3)
		$(CC) -c User.cpp

bacarratSimulator.o: bacarratSimulator.cpp $(DEPS)
		$(CC) -c bacarratSimulator.cpp

bacarratSimulator: Shoe.o Statistics.o User.o $(DEPS)
		$(CC) -o bacarratSimulator $(OBJS)