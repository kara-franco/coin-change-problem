CXX = g++ -std=c++0x 
CXXFLAGS = -Wall -g -O3
PROGS = main

main: main.o filter.o algos.o
	$(CXX) $(CXXFLAGS) -o main main.o filter.o algos.o

main.o: main.cpp filter.h algos.h
	$(CXX) $(CXXFLAGS) -c main.cpp

filter.o: filter.h

algos.o: algos.h filter.h

clean:
	rm -f $(PROGS) *.o *~	
