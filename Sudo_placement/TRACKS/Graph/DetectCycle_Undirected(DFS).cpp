#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


/* This function is used to detect a cycle in undirected graph

*  g[]: array of vectors to represent graph
*  V: number of vertices
*/

int parent[10001];
bool vis[10001];

bool dfs(int src,vector<int> g[])
{
    vis[src]=true; 
    for(int i=0;i<g[src].size();i++)
     {
        if(vis[g[src][i]]==false)
         {
            parent[g[src][i]]=src;
            if(dfs(g[src][i],g))
             return true;
         }
        else
         {
            if(vis[g[src][i]]==true)
             {
                if(parent[src]!=g[src][i])
                 return true;
             }
         }
     }
    return false;
}

bool isCyclic(vector<int> g[], int V)
{
   // Your code here
   memset(vis,false,sizeof(vis));
   memset(parent,-1,sizeof(parent));
   for(int i=0;i<V;i++)
    {
        if(vis[i])
         continue;
        if(dfs(i,g))
         return true;
    }
   return false;    
}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
  // } Driver Code Ends