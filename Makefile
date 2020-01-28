LLMenu: main.o Executive.o
	g++ -g -std=c++11 -Wall main.o Executive.o -o LLMenu

main.o: main.cpp Executive.h
	g++ -g -std=c++11 -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp LinkedList.h LinkedList.cpp Node.h Node.cpp
	g++ -g -std=c++11 -Wall -c Executive.cpp

clean:
	rm *.o LLMenu
