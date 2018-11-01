sort: main.o
	g++ -g main.o -std=c++0x -o sort

main.o: main.cpp
	g++ -c main.cpp -std=c++0x

inputValidation.o: inputValidation.cpp inputValidation.hpp
	g++ -c inputValidation.cpp

clean:
	rm -f *o sort
