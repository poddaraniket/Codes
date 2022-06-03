#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


/* This function is used to detect a cycle in undirected graph

*  g[]: array of vectors to represent graph
*  V: number of vertices
*/

// bool bfs(int src,vector<int> g[])
// {
//     vis[src]=0;
    
// }

bool isCyclic(vector<int> g[], int V)
{
   // Your code here
   int vis[V];
   queue<int> q;
   memset(vis,-1,sizeof(vis));
   for(int i=0;i<V;i++)
    {
        if(vis[i]==-1)
         {
            q.push(i); 
            vis[i]=0; 
            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                vis[u]=1;
                for(int i=0;i<g[u].size();i++)
                 {
                    if(vis[g[u][i]]==-1)
                     {
                         q.push(g[u][i]);
                         vis[g[u][i]]=0;
                     }
                    else if(vis[g[u][i]]==0)   // if any child of a source has 0 in its visited section it is cyle
                     return true;
                 }
            }
         }
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