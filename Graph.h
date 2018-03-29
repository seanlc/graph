#include <iostream>
#include <vector>
#include <algorithm>
#include "Vertex.h"
#include "Edge.h"


using namespace std;

// TODO copy constructor
// TODO assignment operator
class Graph
{
    public:
        Graph(int numV)
	: numVertex(numV), vertexIndexNumber(numV), numEdges(0), edgeIndexNumber(0)
	{
	    gph.reserve(numV);
	    for(int i = 0; i < numVertex; ++i)
	    {
		Vertex v(i);
	        gph.push_back(v);
	    }
	}

        Graph()
        : numVertex(0), vertexIndexNumber(0), numEdges(0), edgeIndexNumber(0)
	{}

	~Graph()
	{
	    for(int i = 0; i < edgeIndexNumber; ++i)
	        delete edges[i];
	}

        vector<Vertex> getVertices()
	{
	    vector<Vertex> tmp = gph;
	    return tmp;
	}
	 
	vector<Edge *> getEdges()
	{
	    vector<Edge *> tmp = edges;
	    return tmp;
	}

	int getNumV() const
	{
	    return numVertex;
	}

	int getNumE() const
	{
	    return numEdges;
	}

	void addEdge(int fromV, int toV, int weight)
	{
	     // create edge
	     Edge * newEdge = new Edge(fromV, toV, weight);
	     //  add edge to edge collection
	     edges.push_back(newEdge);
	     //  add pointer to outEdges of fromV
	     gph[fromV].addOutgoingEdge(newEdge);
	     //  add pointer to inEdges of toV
	     gph[toV].addIncomingEdge(newEdge);
	     // increment number of edges
	     ++edgeIndexNumber;
	     ++numEdges;
	}

	void removeEdgeFromCol(Edge rEdge)
	{
	    edges.erase( remove_if(edges.begin(), edges.end(), [&](Edge * ePtr)
				    {
				        return *ePtr == rEdge;
				    }) , edges.end());
	}

	void removeEdge(int fromV, int toV, int weight)
	{
	    // get edge ptr
	    Edge rEdge = getEdge(fromV, toV, weight);
	    // remove pointer from inEdges of toV
            gph[toV].removeIncomingEdge(rEdge); 
            // remove pointer from outEdges of fromV
	    gph[fromV].removeOutgoingEdge(rEdge);
	    // remove from edge collection
	    removeEdgeFromCol(rEdge);
	    // decrement number of edges
	    --numEdges;
	}

	void addVertex()
	{
	    Vertex v(vertexIndexNumber++);
	    gph.push_back(v);
	    ++numVertex;
	};

	void removeVertex(int index)
	{
	    gph.erase( remove_if( gph.begin(), gph.end(), [&](Vertex v)
				    { 
				        return v.getIndex() == index;
				    }), gph.end());
	    --numVertex;
	}

	bool hasEdge(int fromV, int toV, int weight)
	{
	    Edge tmp(fromV, toV, weight);
	    bool found = false;
	    for_each(edges.begin(), edges.end(), [&](Edge * ePtr)
			    {
			        if(*ePtr == tmp)
			           found = true;	
			    });
	    return found;
	}

	// TODO add exception for nonexistent vertex
	// returns Vertex with index matching provided argument, vertex with index of -1 if no such vertex exists
	Vertex getVertex(int index)
	{
	    Vertex vert(-1);
	    for_each( gph.begin(), gph.end(), [&](Vertex v)   
			    {
			        if(v.getIndex() == index)
				    vert = v;
			    });
	    return vert;
	}

	// TODO add exception for nonexistent edge
	Edge getEdge(int srcV, int destV, int weight)
	{
	    Edge retEdge(-1,-1,-1);
	    for_each( edges.begin(), edges.end(), [&](Edge * e)
			    {
			        if(e->srcIndex == srcV && e->destIndex == destV && e->weight == weight)
				    retEdge = *e;
			    });

	    return retEdge;
	}
        
	vector<Vertex>::iterator begin()
	{
	    return gph.begin();
	}

	vector<Vertex>::iterator end()
	{
	    return gph.end();
	}

	vector<Edge *>::iterator edgeBegin()
	{
	    return edges.begin();
	}

	vector<Edge *>::iterator edgesEnd()
	{
	    return edges.end();
	}

	friend ostream & operator << (ostream & o, Graph & gph)
	{
	    for_each( gph.begin(), gph.end(), [&](Vertex v) 
			    { 
			        o << v << endl;
			    });
	    return o;
	}

    private:
	vector<Vertex> gph;
	vector<Edge *> edges;
	int numVertex;
	int vertexIndexNumber;
	int numEdges;
	int edgeIndexNumber;
};


