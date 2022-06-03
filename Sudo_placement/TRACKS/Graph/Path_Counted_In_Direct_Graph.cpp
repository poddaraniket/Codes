//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }
    
    
 // } Driver Code Ends


//User function Template for C++

// you are required to complete this function
// the function should return the total possible paths possible from s to d
//This function is a member of the Graph class.Expand the driver code to see other members.
bool vis[100];

int countPaths(int s, int d)
{
    // Code here
    memset(vis,false,sizeof(vis));
    int count=0;
    dfs(s,d,count);
    return count;
}

void dfs(int src,int dest,int &count)
{
   // vis[src]=true;
    if(src==dest)
     {
        vis[dest]=false; 
        count++; 
        return;
     }
    else
    {
     vis[src]=true;          // keep track of visited nodes but in a manner that when its all adjacents are called it unvisited 
    for(auto it=adj[src].begin();it!=adj[src].end();it++)           //so that it can nw work as a path for some other path
     {
         if(vis[*it])
          continue;
         dfs(*it,dest,count); 
     }
    vis[src]=false; 
    }
}

// { Driver Code Starts.
};




int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n, e, x, y, s, d;
        cin>>n>>e;
        Graph g(n);
        while(e--){
            cin>>x>>y;
            g.addEdge(x, y);
        }
        cin>>s>>d;
        cout << g.countPaths(s, d) << "\n";
    }
    return 0;
}
  // } Driver Code Ends