#include <bits/stdc++.h>

using namespace std;

int *topoSort(int N, vector<int> adj[]);

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
bool check(int V, int res[], vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return false;
        }
    }
    return true;
}

// Driver Code
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        int *res = topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
}// } Driver Code Ends


// The Graph structure is as folows

/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*   NOTE: You must return dynamically allocated array
*/

int* topoSort(int V, vector<int> adj[]) {
    // Your code here
    static int arr[10001];
    queue<int> q;
    int i,j;
    int indegree[V]={0};
    for(i=0;i<V;i++)
     {
        for(j=0;j<adj[i].size();j++)
         {
            indegree[adj[i][j]]++; 
         }
     }
    for(i=0;i<V;i++)
     {
        if(indegree[i]==0)
         q.push(i);
     }
    int p=0; 
    while(!q.empty())
     {
        int u=q.front();
        arr[p++]=u;
        q.pop();
        for(i=0;i<adj[u].size();i++)
         {
            indegree[adj[u][i]]--;
            if(indegree[adj[u][i]]==0)
             q.push(adj[u][i]);
         }
     }
    return arr; 
}
