all: linkList

linkList: main.o
	g++ -g main.o -std=c++0x -std=c++11 -o linkList

main.o: main.cpp
	g++ -c main.cpp -std=c++0x -std=c++11

clean:
	rm -f *o linkList
