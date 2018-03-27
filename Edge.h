#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// TODO copy constructor
struct Edge
{
    public:
      int srcIndex;
      int destIndex;
      double weight;
      
      Edge(int sv, int dv, double w)
      : srcIndex(sv), destIndex (dv), weight (w)
      {}
      
      Edge()
      : srcIndex(-1), destIndex(-1), weight(-1)
      {}
      
      ~Edge()
      {}

      Edge & operator = (const Edge & that)
      {
	  if(this != &that)
	  {
	     srcIndex = that.srcIndex;
	     destIndex = that.destIndex;
	     weight = that.weight;
	  }
          return *this;
      }

      friend ostream & operator << (ostream & o, const Edge e)
      {
        o << "Edge from vertex " << e.srcIndex  << " to vertex " << e.destIndex << " with weight " << e.weight;
        return o;
      }
};
