#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Edge
{
    private:
      int destIndex;
      double weight;
    public:
      Edge(int dv, double w)
      : destIndex (dv), weight (w)
      {}
      ~Edge()
      {}
      friend ostream & operator << (ostream & o, const Edge e)
      {
        o << "Edge to vertex " << e.destIndex << " with weight " << e.weight;
        return o;
      }
};

class Vertex
{
    private:
    int index;
    int numEdges;
    vector<Edge> aList;
    public:
    void addEdge(int endV, int weight)
    {
        Edge e(endV, weight);
	aList.push_back(e);
	++numEdges;
    }
    Vertex()
    : numEdges(0)
    {}
    ~Vertex()
    {}
    void setIndex(int n)
    {
        index = n;
    }
    int getIndex()
    {
        return index;
    }
    friend ostream & operator <<(ostream & o, const Vertex & v)
    {
        o << "Vertex: " << v.index << endl;
	o << "Edges: " << v.numEdges << endl;
	for(int i = 0; i < v.numEdges; ++i)
	    o << v.aList.at(i) << endl;
	return o;
    }
};

class Graph
{
    public:
        Graph(int numV)
	: numVertex(numV)
	{
	    gph = new Vertex[numV];
	    for(int i = 0; i < numVertex; ++i)
	       gph[i].setIndex(i); 
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

	void addEdge(int fromV, int toV, int weight)
	{
	   gph[fromV].addEdge(toV, weight);
	}

	friend ostream & operator << (ostream & o, const Graph & gph)
	{
	    int numV = gph.getNumV();
	    for(int i = 0; i < numV; ++i)
                cout << gph.vAt(i) << endl;
	   return o;
	}

    private:
	Vertex * gph;
	int numVertex;
};
