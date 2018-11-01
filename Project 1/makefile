antGame: main.o
	g++ main.o -std=c++0x -o antGame

main.o: main.cpp
	g++ -c main.cpp
	
inputValidation.o: inputValidation.cpp inputValidation.hpp
	g++ -c inputValidation.cpp
	
direction.o: direction.cpp direction.hpp
	g++ -c direction.cpp
	
antConstruct.o: antConstruct.cpp antConstruct.hpp
	g++ -c antConstruct.cpp

clean:
	rm *.o antGame