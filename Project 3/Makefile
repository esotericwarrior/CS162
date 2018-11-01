all: dieFight

dieFight: main.o
	g++ -g main.o -std=c++0x -o dieFight

main.o: main.cpp
	g++ -c main.cpp

character.o: character.hpp
	g++ -c character.hpp

die.o: die.cpp die.hpp
	g++ -c die.cpp

inputValidation.o: inputValidation.cpp inputValidation.hpp
	g++ -c inputValidation.cpp

functions.o: functions.cpp functions.hpp
	g++ -c functions.cpp

barbarian.o: barbarian.cpp barbarian.hpp
	g++ -c barbarian.cpp

vampire.o: vampire.cpp vampire.hpp
	g++ -c vampire.cpp

medusa.o: medusa.cpp medusa.hpp
	g++ -c medusa.cpp

blueMen.o: blueMen.cpp blueMen.hpp
	g++ -c blueMen.cpp

harryPotter.o: harryPotter.cpp harryPotter.hpp
	g++ -c harryPotter.cpp

clean:
	rm -f *o dieFight