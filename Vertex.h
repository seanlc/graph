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
      int inDeg;
      int outDeg;
      vector<Edge *> inEdges;
      vector<Edge *> outEdges;

    public:
      Vertex(int i)
      : index(i), inDeg(0), outDeg(0)
      {}

      Vertex()
      : index(-1), inDeg(0), outDeg(0)
      {}

      ~Vertex()
      {}

      void addOutgoingEdge(Edge * e)
      {
          outEdges.push_back(e);
	  ++outDeg;
      }

      void addIncomingEdge(Edge * e)
      {
          inEdges.push_back(e);
	  ++inDeg;
      }

      void removeIncomingEdge(Edge e)
      {
          inEdges.erase( remove_if(inEdges.begin(), inEdges.end(), [&](Edge * ePtr)
			  {
			      return (*ePtr == e);    
			  })  ,inEdges.end());      
	  --inDeg;
      }

      void removeOutgoingEdge(Edge e)
      {
	  outEdges.erase( remove_if(outEdges.begin(), outEdges.end(), [&](Edge * ePtr)
				  {
				      return (*ePtr == e);
				  }) , outEdges.end());
          --outDeg;
      }

      int getNumEdges()
      {
          return inDeg + outDeg;
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
	      inDeg = that.inDeg;
	      outDeg = that.outDeg;
	      inEdges = that.inEdges;
	      outEdges = that.outEdges;
	  }
          return *this;
      }

      friend ostream & operator <<(ostream & o, const Vertex & v)
      {
          o << "Vertex: " << v.index << endl;
	  o << "Incoming Edges: " << endl;
	  for_each(v.inEdges.begin(), v.inEdges.end(), [&](Edge * e)
			  {
			      o << *e << endl;
			  });
	  
	  o << "Outgoing Edges: " << endl;
	  for_each(v.outEdges.begin(), v.outEdges.end(), [&](Edge * e)
			  {
			      o << *e << endl;
			  });
	  return o;
      }
};

