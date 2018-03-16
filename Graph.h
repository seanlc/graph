#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Edge
{
    int destIndex;
    double weight;
    Edge(int dv, double w)
    : destIndex (dv), weight (w)
    {}
    ~Edge()
    {}
};

// TODO add edge
struct Vertex
{
    int index;
    vector<Edge> aList;
    Vertex()
    {}
    ~Vertex()
    {}
};

class Graph
{
    public:
        Graph(int numV)
	: numVertex(numV)
	{
	    gph = new Vertex[numV];
	    for(int i = 0; i < numVertex; ++i)
	    {
	       gph[i].index = i; 
	    }
	}

	~Graph()
	{
	    delete [] gph;
	}

	int getNumV() const
	{
	    return numVertex;
	}

	Vertex vAt(int index) const
	{
	    return gph[index];
	}

	friend ostream & operator << (ostream & o, const Graph & gph)
	{
	    int numV = gph.getNumV();
	    for(int i = 0; i < numV; ++i)
	        o << "Vertex : " << gph.vAt(i).index << endl;
	   // add edges
	   return o;
	}

    private:
	Vertex * gph;
	int numVertex;
};
