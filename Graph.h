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

class Graph
{
    public:
        Graph(int cap)
        : numVertex (cap)
	{
	    vector<Edge> temp;
	    for(int i = 0; i < cap; ++i)
	        buf.push_back(temp);
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
	    return any_of(buf[fromV].begin(), buf[fromV].end(), 
		[&](struct Edge E){ return E.destIndex == toV;  } );   
	} 
	void BFS()
	{
	    static vector<bool> disc(numVertex, false);
	    queue<int> nodeList;
	    nodeList.push(0);
	    int cur;
	    while(nodeList.size() > 0)
	    {
	        cur = nodeList.front();
		nodeList.pop();
	        cout << "vertex " << cur << endl;
		disc[cur] = true;
		for_each(buf[cur].begin(), buf[cur].end(), [&](Edge e)
				{
				    if(! disc[e.destIndex])
				        nodeList.push(e.destIndex); 
				});
	    }
	}
	void DFS(int v)
	{
	    static vector<bool> disc(numVertex, false);
	    cout << "vertex " << v << endl;
	    disc[v] = true;
	    for_each(buf[v].begin(), buf[v].end(), [&] (Edge e)
			    {
			        if( ! disc[e.destIndex])
				    DFS(e.destIndex);
			    });
	}
    private:
        vector<vector<Edge>> buf;
	int numVertex;
};
