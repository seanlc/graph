#include <iostream>
#include "Graph.h"


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

    cout << "hasEdge(0,4,50), 1 expected: " << myGraph.hasEdge(0,4,50) << endl;
    
    myGraph.removeEdge(0,4,50);
    cout << myGraph << endl;
    cout << "hasEdge(0,4,50), 0 expected: " << myGraph.hasEdge(0,4,50) << endl;

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

    cout << "copy after removal of outgoing edge from 0: " << endl;

    Edge e = myGraph.getEdge(0,1,50);
    copy.at(0).removeOutgoingEdge(e);

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
    Graph myGraph(2);
    for_each(myGraph.begin(), myGraph.end(), [&](Vertex v)
		    {
		       myGraph.addEdge(v.getIndex(), 1, 50); 
		    });

    cout << "original: " << endl << myGraph;

    Edge e = myGraph.getEdge(0,1,50);
    Vertex   v = myGraph.getVertex(0);
    v.removeOutgoingEdge(e);

    cout << "vertex after removal of edge: " << v << endl;

    cout << "original: " << endl << myGraph;

}

void testGetEdge()
{
    Graph myGraph(5);
    for_each(myGraph.begin(), myGraph.end(), [&](Vertex v)
		    {
		       myGraph.addEdge(v.getIndex(), 1, 50); 
		    });

    Edge e = myGraph.getEdge(0,1,50);
    e.weight = 100;

    cout << "after changed weight to 100 on edge 0 -> 1: " << endl;
    cout << e << endl;

    cout << "original: " << endl << myGraph;
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

void testVertexRemovalBug()
{
    Graph myGraph(4);
    for_each(myGraph.begin(), myGraph.end(), [&](Vertex v)
		    {
		       myGraph.addEdge(v.getIndex(), 1, 50); 
		    });

    cout << "original: " << endl << myGraph;
    
    myGraph.removeVertex(0);

    myGraph.removeEdge(2,1,50);

    cout << "after removing edge 2 -> 1 with weight 50:" << endl << myGraph << endl;
}

void testGetDegreeOfVertex()
{
    Graph myGraph(4);
    for_each(myGraph.begin(), myGraph.end(), [&](Vertex v)
		    {
		        int index = v.getIndex();
			if(index != 1)
		            myGraph.addEdge(index, 1, 50);
			else
		           myGraph.addEdge(1, 0, 50);	
		    });

    cout << "original: " << endl << myGraph;

    cout << "degree of vertex 1 (4 expected): " << myGraph.getDegreeOfVertex(1) << endl;
    cout << "degree of vertex 0 (2 expected): " << myGraph.getDegreeOfVertex(0) << endl;
    cout << "degree of vertex 3 (1 expected): " << myGraph.getDegreeOfVertex(3) << endl;

}

void testEdgeRemovalBug()
{
    // TODO remove edge from graph
    // TODO update weight of edge in graph for edge added after removed edge
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
//    testRemoveEdge();
//    testVertexRemovalBug();
    testGetDegreeOfVertex();
    return 0;
}
