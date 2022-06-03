#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/* Function to do DFS of graph

g : adjacency list of graph
N : number of vertices

return a list containing the DFS traversal of the given graph
*/
bool vis[10001];
void dfs_helper(int source,vector<int> g[],vector<int> &v)
{
    if(vis[source]==true) 
     return;
    else
     {
        vis[source]=true;
        v.push_back(source);
        for(int i=0;i<g[source].size();i++)
         {
            dfs_helper(g[source][i],g,v); 
         }
     }
}

vector <int> dfs(vector<int> g[], int N)
{
    // Your code here
    memset(vis,false,sizeof(vis));
    vector<int> v;
    dfs_helper(0,g,v);
    return v;
}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {

        int N, E;
        cin>>N>>E;
        
        vector<int> g[N];
        bool vis[N];
        
        memset(vis, false, sizeof(vis));
        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector <int> res = dfs(g, N);
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout<<endl;

    }
}  // } Driver Code Ends