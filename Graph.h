#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// TODO use hasEdge to protect against deleting nonexistent edges in removeEdge()
// TODO implement hasVertex and use it to protect against deleting nonexistent vertex in removeVertex()

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
      bool hasEdge(int toV, int weight)
      {
          return any_of( aList.begin(), aList.end(), [&](Edge e)
			  { 
			      return toV == e.destIndex && weight == e.weight;  
			  });
      }
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
	  for_each(v.aList.begin(), v.aList.end(), [&](Edge e)
			  {  
			      o << e << endl;
			  });
	  return o;
      }
};

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


