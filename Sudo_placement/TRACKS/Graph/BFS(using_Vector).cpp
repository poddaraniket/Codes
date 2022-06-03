#include <bits/stdc++.h>

using namespace std;

vector <int> bfs(vector<int> g[], int N);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector <int> res = bfs(adj, N);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout << endl;
    }
}// } Driver Code Ends


/* You have to complete this function*/

/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/
vector <int> bfs(vector<int> g[], int N) {

    // Your code here
    bool vis[N];
    memset(vis,false,sizeof(vis));
    vector<int> v;
    queue<int> q;
    q.push(0);
    vis[0]=true;
    v.push_back(0);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<g[u].size();i++)
         {
            if(vis[g[u][i]]==false)
            {
             v.push_back(g[u][i]);
             vis[g[u][i]]=true;
             q.push(g[u][i]);
            } 
         }
    }
   return v;    
}