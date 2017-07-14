#include <iostream>
#include <vector>

using namespace std;

struct Edge
{
    double weight;
    int destIndex;
    Edge(double w, int n)
    : weight (w), destIndex (n)
    {}
    ~Edge()
    {}
};
struct Vertex
{
    int data;
    vector<Edge> adj;
    Vertex(int d = 0)
    : data (d)
    {}
    ~Vertex()
    {}
};


class Graph
{
    public:
        Graph(int numV)
        : buf (new Vertex[numV]), numVertex (numV)
	{}
	~Graph()
	{
	    delete [] buf;
	}
	void print();
	void addEdge(int origin, int dest, double weight);
	bool isPath();
	void BFS();
	void DFS();
    private:
	Vertex * buf;
	int numVertex;
};
