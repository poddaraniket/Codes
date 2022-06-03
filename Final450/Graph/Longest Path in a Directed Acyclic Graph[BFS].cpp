// A C++ program to find single source longest distances
// in a DAG


//Time complexity of topological sorting is O(V+E). 
//After finding topological order, the algorithm process all vertices and for every vertex, 
//it runs a loop for all adjacent vertices. Total adjacent vertices in a graph is O(E). 
//So the inner loop runs O(V+E) times
#include <bits/stdc++.h>

using namespace std;
 
// Graph is represented using adjacency list. Every
// node of adjacency list contains vertex number of
// the vertex to which edge connects. It also
// contains weight of the edge
class AdjListNode {
    int v;
    int weight;
   
public:
    AdjListNode(int _v, int _w)
    {
        v = _v;
        weight = _w;
    }
    int getV() { return v; }
    int getWeight() { return weight; }
};
   
// Class to represent a graph using adjacency list
// representation
class Graph {
    int V; // No. of vertices'
   
    // Pointer to an array containing adjacency lists
    list<AdjListNode>* adj;
   
    // A function used by longestPath
    void topologicalSortUtil(int v, bool visited[],
                             stack<int>& Stack);
   
public:
    Graph(int V); // Constructor
    ~Graph(); // Destructor
 
    // function to add an edge to graph
    void addEdge(int u, int v, int weight);
   
    // Finds longest distances from given source vertex
    void longestPath(int s);
};
   
Graph::Graph(int V) // Constructor
{
    this->V = V;
    adj = new list<AdjListNode>[V];
}
 
Graph::~Graph() // Destructor
{
    delete [] adj;
}
 
 
void Graph::addEdge(int u, int v, int weight)
{
    AdjListNode node(v, weight);
    adj[u].push_back(node); // Add v to u's list
}
   
// A recursive function used by longestPath. See below
// link for details
// https:// www.geeksforgeeks.org/topological-sorting/
void Graph::topologicalSortUtil(vector<int>&v)
{
   queue<int> q;
   int indegree[V]={0};
   for(int i=0;i<V;i++)
    {
        for(int j=0;j<adj[i].size();i++)
         {
            indegree[adj[i][j]]++; 
         }
    }
    for(int i=0;i<V;i++)
     {
         if(indegree[i]==0)
          {
            v.push_back(i);
            q.push(i);
          }
     }
    while(!q.empty())
     {
        int u=q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++) 
        {
            indegree[adj[u][i]]--;
            if(indegree[adj[u][i]]==0)
             {
                v.push_back(adj[u][i]);
                q.push(adj[u][i]); 
             }
        }
     }
}
   
// The function to find longest distances from a given vertex.
// It uses recursive topologicalSortUtil() to get topological
// sorting.
void Graph::longestPath(int s)
{
   vector<int> v;
   topologicalSortUtil(v);
   vector<int> dist(V,INT_MIN);
   bool feaisble=false;
   dist[s]=0;
   for(int i=0;i<v.size();i++)
    {
        int u=v[i];
        if(dist[u]!=INT_MIN)
         {
            for (j = adj[u].begin(); j != adj[u].end(); ++j){
             
                if (dist[j->getV()] < dist[u] + j->getWeight())
                 {
                    dist[j->getV()] = dist[u] + j->getWeight();
                 }
            } 
         }
    }
    for(int i=0;i<V;i++)
     {
         if(dist[i]==INT_MIN)
          cout<<"INF"<<" ";
         else
          cout<<dist[i]<<" ";
     }
    cout<<endl; 
}
   
// Driver program to test above functions
int main()
{
    // Create a graph given in the above diagram.
    // Here vertex numbers are 0, 1, 2, 3, 4, 5 with
    // following mappings:
    // 0=r, 1=s, 2=t, 3=x, 4=y, 5=z
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
   
    int s = 1;
    cout << "Following are longest distances from "
            "source vertex "
         << s << " \n";
    g.longestPath(s);
   
    return 0;
}