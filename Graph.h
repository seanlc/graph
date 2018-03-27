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
	: numVertex(numV), vertexIndexNumber(numV)
	{
	    gph.reserve(numV);
	    for(int i = 0; i < numVertex; ++i)
	    {
		Vertex v(i);
	        gph.push_back(v);
	    }
	}

        Graph()
        : numVertex(0), vertexIndexNumber(0)	
	{}

	~Graph()
	{}

        vector<Vertex> getVertices()
	{
	    vector<Vertex> tmp = gph;
	    return tmp;
	}
	 
	vector<Edge> getEdges()
	{
	    int nEdges = getNumE();
	    vector<Edge> tmp;
	    tmp.reserve(nEdges);
	    for_each(gph.begin(), gph.end(), [&](Vertex v)
			    {
			        for_each(v.edgeBegin(), v.edgeEnd(), [&](Edge e)
						{
						    tmp.push_back(e);
						});    
			    });
	    return tmp;
	}

	int getNumV() const
	{
	    return numVertex;
	}

	int getNumE() const
	{
	    int numEdges = 0;
	    for_each(gph.begin(), gph.end(), [&](Vertex v)
			    {
			        numEdges += v.getNumEdges();
			    });
	    return numEdges;
	}

	void addEdge(int fromV, int toV, int weight)
	{
	   gph[fromV].addEdge(toV, weight);
	}

	void removeEdge(int fromV, int toV, int weight)
	{
            gph[fromV].removeEdge(toV, weight);
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
	    return gph[fromV].hasEdge(toV, weight);
	}

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

        vector<Vertex>::iterator begin()
	{
	    return gph.begin();
	}

	vector<Vertex>::iterator end()
	{
	    return gph.end();
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
	int numVertex;
	int vertexIndexNumber;
};


