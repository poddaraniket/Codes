#include <bits/stdc++.h>
using namespace std;

int isBridge(vector<int> adj[], int V);
// Driver Program
int main() {

    int T;
    cin >> T;
    while (T--) {
        int s, N;
        cin >> s >> N;
        vector<int> adj[s];
        for (int i = 0; i < N; i++) {
            int u, v;
            cin >> u >> v;
            adj[u-1].push_back (v-1);
            adj[v-1].push_back (u-1);
        }
        cout<<isBridge(adj, s)<<endl;
    }
}
// } Driver Code Ends


// your task is to complete this function

/*
adj : adjacency list of the graph
V : Number of vertices
s,e : End vertices of the given edge
*/
set<int> cutvertex;
int in[100000],low[100000];
bool vis[100000];
int timer;

void dfs(vector<int> adj[],int node,int par)
{
  //cout<<node<<endl;    
  vis[node]=true;
  in[node]=timer;
  low[node]=timer;
  timer++;
  int children=0;
  for(int i=0;i<adj[node].size();i++)
  {
      if(adj[node][i]==par)
        continue;
      if(vis[adj[node][i]])               // Back edge
       {
          low[node]=min(low[node],in[adj[node][i]]); 
       }
      else              //Forward Edge
       {
           dfs(adj,adj[node][i],node);
           if(low[adj[node][i]]>=in[node] && par!=-1)
           {
           // cout<<node<<endl;   
            cutvertex.insert(node);
           }
           ++children;
           low[node]=min(low[node],low[adj[node][i]]);    
       }
  }
 if(par==-1 && children>1)
  cutvertex.insert(node);
}

int isBridge(vector<int> adj[], int V) {
    // Code here
    timer=0;
    memset(vis,false,sizeof(vis));
    cutvertex.clear();
    for(int i=0;i<V;i++)
     {
        if(vis[i])
         continue;
        dfs(adj,i,-1); 
     }
    return cutvertex.size(); 
}