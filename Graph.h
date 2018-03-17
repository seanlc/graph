#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// TODO implement iterator for Graph
// TODO implement hasEdge and use it to protect against deleting nonexistent edges in removeEdge()

class Edge
{
    public:
      int destIndex;
      double weight;
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
      void removeEdge(int endV, int weight)
      {
          aList.erase( remove_if(aList.begin(), aList.end(), [&](Edge  e)
			  {
			      return e.weight == weight && e.destIndex == endV;
			  }));
	  --numEdges;
      }
      bool hasEdge(int toV, int weight);
      Vertex(int i)
      : index(i), numEdges(0)
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
	  for_each(v.aList.begin(), v.aList.end(), [&](Edge e){  o << e << endl;});
	  return o;
      }
};

class Graph
{
    public:
        Graph(int numV)
	: numVertex(numV)
	{
	    gph.reserve(numV);
	    for(int i = 0; i < numVertex; ++i)
	    {
		Vertex v(i);
	        gph.push_back(v);
	    }
	}

	~Graph()
	{}

	int getNumV() const
	{
	    return numVertex;
	}


	void addEdge(int fromV, int toV, int weight)
	{
	   gph[fromV].addEdge(toV, weight);
	}

	void removeEdge(int fromV, int toV, int weight)
	{
            gph[fromV].removeEdge(toV, weight);
	}

	bool hasEdge(int fromV, int toV, int weight);

	Vertex vAt(int i) const
	{
	    return gph[i];
	}

	friend ostream & operator << (ostream & o, const Graph & gph)
	{
	    int numV = gph.getNumV();
	    for(int i = 0; i < numV; ++i)
                cout << gph.vAt(i) << endl;
	   return o;
	}

    private:
	vector<Vertex> gph;
	int numVertex;
};
