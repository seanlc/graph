CC= g++
CFLAGS= -ggdb -Wall -std=c++11

main: main.cpp Graph.h.gch Vertex.h.gch Edge.h.gch
	$(CC) $(CFLAGS) -o main main.cpp
Graph.h.gch: Graph.h
	$(CC) $(CFLAGS) Graph.h
Vertex.h.gch: Vertex.h
	$(CC) $(CFLAGS) Vertex.h
Edge.h.gch: Edge.h
	$(CC) $(CFLAGS) Edge.h
clean:
	rm -f main Graph.h.gch Vertex.h.gch Edge.h.gch
valgrind:
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes --show-reachable=yes ./main
