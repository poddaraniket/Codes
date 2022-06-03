#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
int parent[10001];
bool vis[10001];

bool dfs(int src,vector<int> adj[])
{
    vis[src]=true; 
    for(int i=0;i<adj[src].size();i++)
     {
        if(vis[adj[src][i]]==false)
         {
            parent[adj[src][i]]=src;
            if(dfs(adj[src][i],adj))
             return true;
         }
        else
         {
            if(vis[adj[src][i]]==true)
             {
                int f=adj[src][i]; 
                int t=src;
                while(t!=f)
                 {
                    t=parent[t]; 
                    if(t==-1)
                     break;
                 }
                if(f==t)
                 return true;
             }
         }
     }
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
    memset(vis,false,sizeof(vis));
    memset(parent,-1,sizeof(parent));
    for(int i=0;i<V;i++)
    {
        if(vis[i])
         continue;
        if(dfs(i,adj))
         return true;
    }
   return false;    
}

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends