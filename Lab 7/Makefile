all: que

que: main.o
	g++ -g main.o -std=c++0x -o que

main.o: main.cpp
	g++ -c main.cpp

queue.o: queue.cpp queue.hpp
	g++ -c queue.cpp

inputValidation.o: inputValidation.cpp inputValidation.hpp
	g++ -c inputValidation.cpp

clean:
	rm -f *o que