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

void testNumEdges()
{
    Graph myGraph(5);

    for_each(myGraph.begin(), myGraph.end(), [&](Vertex v)
		    {
		        int index = v.getIndex();
                        for(int i = 0; i < 5; ++i)
                            myGraph.addEdge(index,i,50);
		    });

    cout << "number of edges (25 expected): " << myGraph.getNumE() << endl; 
}

void testNumVertices()
{
     Graph myGraph(0);
     Graph myGraph2(10);

     cout << "number of vertices for graph 1 (0 expected): " << myGraph.getNumV() << endl;
     cout << "number of vertices for graph 2 (10 expected): " << myGraph2.getNumV() << endl;
}

void testGetVertex()
{
    Graph myGraph(5);
    for_each(myGraph.begin(), myGraph.end(), [&](Vertex v)
		    {
		       myGraph.addEdge(v.getIndex(), 1, 50); 
		    });

    cout << "original: " << endl << myGraph;

    vector<Vertex> copy = myGraph.getVertices();

    cout << "copy after removal of edge: " << endl;

//  TODO rewrite
//    copy.at(0).removeEdge(1,50);

    for_each(copy.begin(), copy.end(), [&](Vertex v)
		    {
		        cout << v << endl;
		    });

    cout << "original: " << endl << myGraph;
}

void testGetEdges()
{
    Graph myGraph(5);
    for_each(myGraph.begin(), myGraph.end(), [&](Vertex v)
		    {
		       myGraph.addEdge(v.getIndex(), 1, 50); 
		    });

    cout << "original: " << endl << myGraph;


    vector<Edge *> e = myGraph.getEdges();
    
    cout << "edge collection: " << endl;
    for_each(e.begin(), e.end(), [&](Edge * e)
		    {
		        cout << *e << endl;
		    });
}

void testGetVertexSingle()
{
    Graph myGraph(5);
    for_each(myGraph.begin(), myGraph.end(), [&](Vertex v)
		    {
		       myGraph.addEdge(v.getIndex(), 1, 50); 
		    });

    cout << "original: " << endl << myGraph;

//    Vertex v= myGraph.getVertex(4);
//    v.removeEdge(1,50);

//    cout << "vertex after removal of edge: " << v << endl;

//    cout << "original: " << endl << myGraph;

}

void testGetEdge()
{
    Graph myGraph(5);
    for_each(myGraph.begin(), myGraph.end(), [&](Vertex v)
		    {
		       myGraph.addEdge(v.getIndex(), 1, 50); 
		    });

    Edge e = myGraph.getEdge(0,1,50);

    cout << "returned edge: " << endl;
    cout << e << endl;
}

void testRemoveEdge()
{
    Graph myGraph(5);
    for_each(myGraph.begin(), myGraph.end(), [&](Vertex v)
		    {
		       myGraph.addEdge(v.getIndex(), 1, 50); 
		    });

    cout << "original: " << endl << myGraph;
    
    myGraph.removeEdge(0,1,50);

    cout << "after removal of 0->1 with weight 50" << endl << myGraph;
}

int main()
{
//    testConstr();
//    testAddRemoveEdge();
//    testAddRemoveVertex();
//    testNumEdges();
//    testNumVertices();
//    testGetVertex();
//    testGetEdges();
//    testGetVertexSingle();
//    testGetEdge();
    testRemoveEdge();
    return 0;
}
