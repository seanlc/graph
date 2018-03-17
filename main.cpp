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
    myGraph.addEdge(0,4,50);
    cout << myGraph << endl;

    myGraph.removeEdge(0,4,50);
    cout << myGraph << endl;
}

int main()
{
//    testConstr();
    testAddEdge();
    return 0;
}
