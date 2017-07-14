CC= g++
CFLAGS= -ggdb -Wall -std=c++11

main: main.cpp Graph.h.gch
	$(CC) $(CFLAGS) -o main main.cpp
Graph.h.gch: Graph.h
	$(CC) $(CFLAGS) Graph.h
clean:
	rm -f main Graph.h.gch
valgrind:
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes --show-reachable=yes ./main
