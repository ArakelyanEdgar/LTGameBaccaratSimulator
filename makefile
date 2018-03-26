#EDGAR ARAKELYAN
#BACARRAT SIMULATION MAKEFILE

OBJS = Shoe.o Statistics.o User.o baccaratSimulator.o
CC = g++ -Wall -pedantic -std=c++11 -g
DEPS = Shoe.h Statistics.h User.h
DEPS1 = Shoe.h
DEPS2 = Statistics.h
DEPS3 = User.h

all: baccaratSimulator

Shoe.o: Shoe.cpp $(DEPS1)
		$(CC) -c Shoe.cpp

Statistics.o: Statistics.cpp $(DEPS2)
		$(CC) -c Statistics.cpp

User.o: User.cpp $(DEPS3)
		$(CC) -c User.cpp

baccaratSimulator.o: baccaratSimulator.cpp $(DEPS)
		$(CC) -c baccaratSimulator.cpp

baccaratSimulator: Shoe.o Statistics.o User.o baccaratSimulator.o $(DEPS)
		$(CC) -o baccaratSimulator $(OBJS)






clean:
	rm -f $(OBJS)