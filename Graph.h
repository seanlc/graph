#include <iostream>
#include <vector>
#include <algorithm>

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

class Graph
{
    public:
        Graph(int cap)
        : numVertex (cap)
	{
	    vector<Edge> temp;
	    for(int i = 0; i < cap; ++i)
	    {
	       buf.push_back(temp); 
	    }
	}
	~Graph()
	{}
	void print();
	void addEdge(int org, int dest, double weight)
	{
	    Edge temp(dest, weight);
	    buf[org].push_back(temp);
	}
	bool isAdj(int fromV, int toV)
	{
	    if( any_of(buf[fromV].begin(), buf[fromV].end(), 
		[&](struct Edge E){ return E.destIndex == toV;  } )   
	      )
	        return true;
	    else
		return false;
	} 
	void BFS();
	void DFS();
    private:
        vector<vector<Edge>> buf;
	int numVertex;
};
