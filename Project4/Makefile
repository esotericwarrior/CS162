dieFight: main.o
	g++ -g main.o -std=c++0x -o dieFight

main.o: main.cpp
	g++ -c main.cpp -std=c++0x

character.o: Character.hpp
	g++ -c Character.hpp

die.o: Die.cpp Die.hpp
	g++ -c Die.cpp

inputValidation.o: InputValidation.cpp InputValidation.hpp
	g++ -c InputValidation.cpp
	
queue.o: Queue.cpp Queue.hpp
	g++ -c Queue.cpp

functions.o: Functions.cpp Functions.hpp
	g++ -c Functions.cpp

barbarian.o: Barbarian.cpp Barbarian.hpp
	g++ -c Barbarian.cpp

vampire.o: Vampire.cpp Vampire.hpp
	g++ -c Vampire.cpp

medusa.o: Medusa.cpp Medusa.hpp
	g++ -c medusa.cpp

blueMen.o: BlueMen.cpp BlueMen.hpp
	g++ -c BlueMen.cpp

harryPotter.o: HarryPotter.cpp HarryPotter.hpp
	g++ -c HarryPotter.cpp
	
tournament.o: Tournament.hpp Tournament.cpp
	g++ -c Tournament.cpp

losers.o: Losers.hpp Losers.cpp
	g++ -c Losers.cpp

clean:
	rm -f *o dieFight