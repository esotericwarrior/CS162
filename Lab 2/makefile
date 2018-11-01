letterFrequency: main.o
	g++ -g main.o -std=c++0x -o letterFrequency

main.o: main.cpp
	g++ -c main.cpp
	
output.cpp.o: output.cpp output.hpp
	g++ -c output.cpp

clean:
	rm *.o charCount