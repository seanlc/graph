#include <iostream>
#include "Graph.h"

using namespace std;

void testConstr()
{
    Graph myGraph(20);
    cout << myGraph << endl;
}

void testAddRemoveEdge()
{
    Graph myGraph(5);
    myGraph.addEdge(0,4,50);
    cout << myGraph << endl;

    cout << "hasEdge(0,4,50): " << myGraph.hasEdge(0,4,50) << endl;
    
    myGraph.removeEdge(0,4,50);
    cout << myGraph << endl;
    cout << "hasEdge(0,4,50): " << myGraph.hasEdge(0,4,50) << endl;

}

void testAddRemoveVertex()
{
    Graph myGraph(5);
    
    cout << "init graph"  << endl;
    cout << myGraph << endl;
    
    myGraph.addVertex();
    cout << "after call to addVertex()" << endl;
    cout << myGraph << endl;

    myGraph.removeVertex(5);
    cout << "after call to removeVertex(5)" << endl;
    cout << myGraph << endl;
}

int main()
{
//    testConstr();
//    testAddRemoveEdge();
    testAddRemoveVertex();
    return 0;
}
