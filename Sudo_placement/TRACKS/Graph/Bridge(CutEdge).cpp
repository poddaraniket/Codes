// Initial template
#include <bits/stdc++.h>
using namespace std;

bool isBridge(list<int> adj[], int V, int u, int v);
// Driver Program
int main() {

    int T;
    cin >> T;
    while (T--) {
        int s, N;
        cin >> s >> N;
        list<int> *adj = new list<int>[s];
        for (int i = 0; i < N; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        int a, b;
        cin >> a >> b;

        if (isBridge(adj, s, a, b))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}
// } Driver Code Ends


// your task is to complete this function

/*
adj : adjacency list of the graph
V : Number of vertices
s,e : End vertices of the given edge
*/
vector<pair<int,int>> v;
int in[100000],low[100000];
bool vis[100000];
int timer;

void dfs(vector<int> g[],int node,int par)
{
  vis[node]=true;
  in[node]=timer;
  low[node]=timer;
  timer++;
  for(int i=0;i<g[node].size();i++)
  {
      if(g[node][i]==par)
        continue;
      if(vis[g[node][i]])
       {
          low[node]=min(low[node],in[g[node][i]]); 
       }
      else
       {
           dfs(g,g[node][i],node);
           if(low[g[node][i]]>in[node])
            v.push_back(make_pair(g[node][i],node));
           low[node]=min(low[node],low[g[node][i]]);    
       }
  }
}

bool isBridge(list<int> adj[], int V, int s, int e) {
    // Code here
    //memset(in,0,sizeof(in));
    v.clear();
    memset(vis,false,sizeof(vis));
    vector<int> g[V];
    for(int i=0;i<V;i++)
     {
        for(auto it=adj[i].begin();it!=adj[i].end();it++)
         g[i].push_back(*it);
     }
    for(int i=0;i<V;i++)
     {
        if(vis[i])
         continue;
        dfs(g,i,-1); 
     }
    for(int i=0;i<v.size();i++)
     {
        if(s==v[i].first || s==v[i].second)
         {
            if(e==v[i].first || e==v[i].second)
              return true;
         }
     }
    return false; 
}