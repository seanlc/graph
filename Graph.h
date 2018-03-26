#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// TODO default constructor
// TODO copy constructor
// TODO assignment operator
struct Edge
{
    public:
      int srcIndex;
      int destIndex;
      double weight;
      Edge(int sv, int dv, double w)
      : srcIndex(sv), destIndex (dv), weight (w)
      {}
      ~Edge()
      {}
      friend ostream & operator << (ostream & o, const Edge e)
      {
        o << "Edge from vertex " << e.srcIndex  << " to vertex " << e.destIndex << " with weight " << e.weight;
        return o;
      }
};

// TODO default constructor
// TODO copy constructor
// TODO assignment operator
class Vertex
{
    private:
      int index;
      int numEdges;
      vector<Edge> aList;
    public:
      Vertex(int i)
      : index(i), numEdges(0)
      {}
      ~Vertex()
      {}
      vector<Edge>::iterator edgeBegin()
      {
          return aList.begin(); 
      }
      vector<Edge>::iterator edgeEnd()
      {
          return aList.end();
      }
      void addEdge(int endV, int weight)
      {
          Edge e(index, endV, weight);
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
      int getNumEdges()
      {
          return numEdges;
      }
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

// TODO default constructor
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

	// TODO test will likely not work properly until assignment operator for vertex is implemented
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


