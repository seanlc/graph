#include <iostream>
#include <vector>
#include <algorithm>
#include "Edge.h"

using namespace std;

// TODO copy constructor
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

      Vertex()
      : index(-1), numEdges(0)
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
 
      Vertex & operator = (const Vertex & that)
      {
          if(this != &that)
	  {
	      index = that.index;
	      numEdges = that.numEdges; 
	      aList = that.aList;
	  }
          return *this;
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

