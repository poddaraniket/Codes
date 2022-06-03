//O(N+M)

#include <bits/stdc++.h>
using namespace std;
 
void dijkstra(vector<pair<int,int>> adj[],int src,int size,vector<int> &dist){
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++){
            int v=adj[u][i].first;
            int wt=adj[u][i].second;
            if(dist[u]+wt<dist[v])
             {
                 dist[v]=dist[u]+wt;
                 q.push(v);
             }
        }
    }
} 
 
void minCostPath(vector<pair<int, pair<int, int> > >& edges,int n, int M){
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<edges.size();i++){
        int src=edges[i].first;
        int dest=edges[i].second.first;
        int wt=edges[i].second.second;
        adj[src].push_back({dest,wt});
        adj[dest].push_back({src,wt});
    }
    
    vector<int> dist_from_source(n+1,INT_MAX);
    dist_from_source[1]=0;
    dijkstra(adj,1,n+1,dist_from_source); 
    vector<int> dist_from_dest(n+1,INT_MAX);
    dist_from_dest[n]=0;
    dijkstra(adj,n,n+1,dist_from_dest);
    int minCost=INT_MAX;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second.first;
        int wt=edges[i].second.second;
        minCost=min(minCost,dist_from_source[u]+wt/2+dist_from_dest[v]);
    }
    cout<< minCost <<endl;
}

int main()
{
    // Give Nodes and Edges
    int N = 3;
    int M = 3;
  
    // Given Edges with cost
    vector<pair<int, pair<int, int> > > edges;
  
    edges.push_back({ 2, { 3, 1 } });
    edges.push_back({ 1, { 3, 7 } });
    edges.push_back({ 2, { 1, 5 } });
  
    // Function Call
    minCostPath(edges, N, M);
    return 0;
}