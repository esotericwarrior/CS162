all: doodle

doodle: main.o
	g++ -g main.o -std=c++0x -o doodle

main.o: main.cpp
	g++ -c main.cpp

critter.o: critter.cpp critter.hpp
	g++ -c critter.cpp

doodlebug.o: doodlebug.cpp doodlebug.hpp
	g++ -c doodlebug.cpp

ant.o: ant.cpp ant.hpp
	g++ -c ant.cpp

clean:
	rm -f *o doodle