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
bool vis[100000];

void dfs(vector<int>g[],int src)
{
    vis[src]=true;
    for(int i=0;i<g[src].size();i++)
     {
        if(!(vis[g[src][i]]))
         dfs(g,g[src][i]);
     }
}

bool isBridge(list<int> adj[], int V, int s, int e) {
    // Code here
    memset(vis,false,sizeof(vis));
    vector<int> g[V];
    for(int i=0;i<V;i++)
     {
        for(auto it=adj[i].begin();it!=adj[i].end();it++)
         g[i].push_back(*it);
     }
    for(int i=0;i<g[s].size();i++)
     {
        if(g[s][i]==e)
        {
         g[s].erase(g[s].begin()+i);
         break;
        }
     }
    for(int i=0;i<g[e].size();i++)
     {
        if(g[e][i]==s)
        {
         g[e].erase(g[e].begin()+i);
         break;
        }
     }
    dfs(g,s);
    if(!(vis[e]))
     return true;
    return false; 
}