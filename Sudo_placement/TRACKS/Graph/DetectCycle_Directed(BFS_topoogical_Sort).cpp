#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/

bool isCyclic(int V, vector<int> adj[])
{
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
        p++;
        q.pop();
        for(i=0;i<adj[u].size();i++)
         {
            indegree[adj[u][i]]--;
            if(indegree[adj[u][i]]==0)
             q.push(adj[u][i]);
         }
     }
    if(p<V)
     return true;
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