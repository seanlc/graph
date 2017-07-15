#include <iostream>
#include "Graph.h"

using namespace std;

void testConstr()
{
    Graph myGraph(20);
}

void testAddEdge()
{
    Graph myGraph(5);
    myGraph.addEdge(0,4,50);
    cout << "edge from 0 to 4: " << myGraph.isAdj(0,4) << endl;
    cout << "edge from 4 to 0: " << myGraph.isAdj(4,0) << endl;
}

void testDFS()
{
    Graph myGraph(7);
    myGraph.addEdge(0,1,1);
    myGraph.addEdge(0,2,1);
    myGraph.addEdge(0,3,1);
    myGraph.addEdge(1,4,1);
    myGraph.addEdge(1,5,1);
    myGraph.addEdge(2,6,1);
    myGraph.addEdge(5,3,1);
    myGraph.DFS(0);
}

int main()
{
//    testConstr();
//    testAddEdge();
    testDFS();
    return 0;
}
