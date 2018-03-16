#include <iostream>
#include "Graph.h"

using namespace std;

void testConstr()
{
    Graph myGraph(20);
    cout << myGraph << endl;
}

void testAddEdge()
{
    Graph myGraph(5);
//    myGraph.addEdge(0,4,50);
//    cout << "edge from 0 to 4: " << myGraph.hasEdge(0,4) << endl;
//    cout << "edge from 4 to 0: " << myGraph.hasEdge(4,0) << endl;
}

int main()
{
    testConstr();
//    testAddEdge();
    return 0;
}
