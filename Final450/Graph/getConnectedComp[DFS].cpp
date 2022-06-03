#include <bits/stdc++.h>
using namespace std;
 
// Graph class represents a undirected graph
// using adjacency list representation
class Graph {
    // No. of vertices
    int V;
 
    // Pointer to an array containing adjacency lists
    list<int>* adj;
 
    // A function used by DFS
    void DFSUtil(int v, bool visited[]);
 
public:
    // Constructor
    Graph(int V);
 
    void addEdge(int v, int w);
    int NumberOfconnectedComponents();
};
 
// Function to return the number of
// connected components in an undirected graph
int Graph::NumberOfconnectedComponents()
{
 
    // Mark all the vertices as not visited
    int count=0;
    bool vis[V];
    memset(vis,false,sizeof(vis));
    
    for(int i=0;i<V;i++)
     {
        if(!vis[i])
        {
            count++;
            DFSUtil(i,vis);
        }
     }
    return count; 
}
 
void Graph::DFSUtil(int v, bool vis[])
{
    // Mark the current node as visited
    vis[v]=true;
    for(auto it=adj[v].begin();it!=adj[v].end();it++){
        if(!vis[*it])
         DFSUtil(*it,vis);
    }
}
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
// Add an undirected edge
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}
 
// Driver code
int main()
{
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
 
    cout << g.NumberOfconnectedComponents();
 
    return 0;
}